//
// Created by ggssh on 2021/10/9 0009.
//

#ifndef SILLYLANG_CODE_GEN_H
#define SILLYLANG_CODE_GEN_H

#include <deque>
#include <unordered_map>
#include <tuple>
#include <string>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include "ast.h"
#include "runtime.h"
#include "error_reporter.h"

using namespace llvm;
using namespace nyar::ast;

/**
 * 中间代码生成
 */
class CodeGenerator : public nyar::ast::AstVisitor {
private:
    void visit(nyar::ast::CompUnit *node) override;

    void visit(nyar::ast::FuncDef *node) override;

    void visit(nyar::ast::FuncCallStmt *node) override;

    void visit(nyar::ast::LValExpr *node) override;

    void visit(nyar::ast::Block *node) override;

    void visit(ReturnStmt *node) override;

    void visit(nyar::ast::BinopExpr *node) override;

    void visit(nyar::ast::VarDefStmt *node) override;

    void visit(nyar::ast::AssignStmt *node) override;

    void visit(nyar::ast::IfStmt *node) override;

    void visit(nyar::ast::Number *node) override;

    void visit(nyar::ast::WhileStmt *node) override;

    void visit(nyar::ast::UnaryopExpr *node) override;

    void visit(nyar::ast::EmptyStmt *node) override;

    void visit(nyar::ast::Cond *node) override;

    // 以下为codegen中需要用到的所有成员变量
    llvm::LLVMContext &context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;// 要使用module.get()来获取module的指针
//    std::unique_ptr<RuntimeInfo> runtime;// 运行时

    // 变量表 key:变量名 value分别为变量地址在LLVM数据结构中的表示,是否为常量,是否为数组
    std::deque<std::unordered_map<std::string, std::tuple<llvm::Value *, bool, bool>>> variables;
    // 函数表 key:函数名 value:函数对象指针
    std::unordered_map<std::string, llvm::Function *> functions;

    llvm::Value *value_result;// 保存其他表达式(如二元表达式)的结果
    int const_result;// 保存常量/数值表达式的结果
    llvm::Function *current_funciton;// 保存当前正在生成的函数

    int bb_count;// 统计BaseBlock的数量
    bool lval_as_rval;// 当前上下文要以何种方式引用正要处理的左值,当值为true时说明其将要作为某个赋值语句的右值
    bool in_global;// 当前是否处于全局作用域
    bool constexpr_expected;

    // ErrorReporter对象,用于codegen的过程中报错
    nyar::ErrorReporter &err;
    bool error_flag;
public:
    /**
     * 构造函数中,成员变量一定要通过初始化列表来初始化的有以下几种情况:
     * 1.const常量成员,因为常量只能在初始化,不能赋值,所以必须放在初始化列表中;
     * 2.引用类型,引用必须在定义的时候初始化,并且不能重新赋值,所以也要写在初始化列表中;
     * 3.没有默认构造函数的类类型,因为使用初始化列表可以不必调用默认构造函数来初始化,而是直接调用拷贝构造函数;
     * @param ctx
     * @param err
     */
    CodeGenerator(llvm::LLVMContext &ctx, nyar::ErrorReporter &err) :
            context(ctx), builder(ctx), err(err) {
    }

    /**
     * 获得当前codegen的module
     * @return
     */
    std::unique_ptr<llvm::Module> get_module() {
        return std::move(module);
    }

    /**
     * 获得当前codegen的运行时信息
     * @return
     */
     /*
    std::unique_ptr<RuntimeInfo> get_runtime_info() {
        return std::move(runtime);
    }
    void build(std::string name, std::shared_ptr<nyar::ast::Node> tree) {
        // 初始化runtime
        module = std::make_unique<llvm::Module>(name, context);
        runtime = std::make_unique<RuntimeInfo>(module.get());

        enter_scope();
        for (const auto &item: runtime->get_language_symbols()) {
            llvm::GlobalValue *val;
            std::string name;
            bool is_function;
            bool is_const;
            bool is_array;
            std::tie(name, val, is_function, is_const, is_array) = item;
            if (is_function)
                functions[name] = static_cast<llvm::Function *>(val);
            else
                declare_variable(name, val, is_const, is_array);
        }
        lval_as_rval = true;
        in_global = true;
        constexpr_expected = false;

        // 递归调用codegen
        tree->accept(*this);
        // 清除IRBuilder插入点并将其移除build module
        builder.ClearInsertionPoint();
        exit_scope();
    }*/

    void build(const std::string &name, const std::shared_ptr<nyar::ast::Node> &tree) {
        module = std::make_unique<llvm::Module>(name, context);

        enter_scope();
        lval_as_rval = true;
        in_global = true;
        constexpr_expected = false;
        error_flag = false;// 初始时将出错标记设置为false

        // 递归调用codegen
        tree->accept(*this);
        // 清除IRBuilder插入点并将其移出build module
        builder.ClearInsertionPoint();
        exit_scope();
    }

private:

    /**
     * 维护作用域,创建新的数据结构以待新的作用域中的变量加入
     */
    void enter_scope() {
        variables.emplace_front();
    }

    /**
     * 处理完毕,销毁当前作用域中的符号,并将当前作用域更新回退到外围最近的作用域
     */
    void exit_scope() {
        variables.pop_front();
    }

    /**
     * 查找变量
     * @param name
     * @return
     */
    std::tuple<llvm::Value *, bool, bool> lookup_variable(const std::string& name) {
        for (auto item: variables) {
            if (item.count(name)) {
                return item[name];
            }
        }
        return std::make_tuple((llvm::Value *) nullptr, false, false);
    }

    /**
     * 声明新变量
     * @param name
     * @param var_ptr
     * @param is_const
     * @param is_array
     * @return
     */
    bool declare_variable(const std::string& name, llvm::Value *var_ptr, bool is_const, bool is_array) {
        // 如果已经声明了则返回false
        if (variables.front().count(name))
            return false;
        variables.front()[name] = std::make_tuple(var_ptr, is_const, is_array);
        return true;
    }
};

#endif // SILLYLANG_CODE_GEN_H
