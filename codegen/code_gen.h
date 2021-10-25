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

using namespace llvm;

/**
 * 中间代码生成
 */
class CodeGenerator : public nyar::ast::AstVisitor {
public:
    void visit(nyar::ast::CompUnit *node) override;

    void visit(nyar::ast::FuncDef *node) override;

    void visit(nyar::ast::FuncCallStmt *node) override;

    void visit(nyar::ast::LValExpr *node) override;

    void visit(nyar::ast::Block *node) override;

    void visit(nyar::ast::BinopExpr *node) override;

    void visit(nyar::ast::VarDefStmt *node) override;

    void visit(nyar::ast::AssignStmt *node) override;

    void visit(nyar::ast::IfStmt *node) override;

    void visit(nyar::ast::Interger *node) override;

    void visit(nyar::ast::WhileStmt *node) override;

    void visit(nyar::ast::UnaryopExpr *node) override;

    void visit(nyar::ast::EmptyStmt *node) override;

    void visit(nyar::ast::Cond *node) override;

private:
    llvm::LLVMContext &context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;// 要使用module.get()来获取module的指针
    std::unique_ptr<RuntimeInfo> runtime;// 运行时

    llvm::Value *value_result;// 保存其他表达式的结果
    int const_result;// 保存常量表达式的结果
    llvm::Function *current_funciton;// 保存当前正在生成的函数

    int bb_count;// 统计BaseBlock的数量
    bool lval_as_rval;// 当前上下文要以何种方式引用正要处理的左值
    bool in_global;// 当前
    bool constexpr_expected;

    // todo 错误处理
public:
    CodeGenerator(llvm::LLVMContext &ctx) :
            context(ctx), builder(ctx) {
    }

    std::unique_ptr<llvm::Module> get_module() {
        return std::move(module);
    }

    std::unique_ptr<RuntimeInfo> get_runtime_info() {
        return std::move(runtime);
    }

    void build(std::string name, std::shared_ptr<nyar::ast::Node> tree) {
        // Initialize environment
        module = std::make_unique<llvm::Module>(name, context);
        runtime = std::make_unique<RuntimeInfo>(module.get());

        enter_scope();
        for (auto item: runtime->get_language_symbols()) {
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

        // start building by starting iterate over the syntax tree
        tree->accept(*this);
        // Finish by clear IRBuilder's insertion point and moving away built module
        builder.ClearInsertionPoint();
        exit_scope();
    }

private:
    // 变量表 key:变量名 value分别为变量地址在LLVM数据结构中的表示,是否为常量,是否为数组
    std::deque<std::unordered_map<std::string, std::tuple<llvm::Value *, bool, bool>>> variables;
    // 函数表 key:函数名 value:函数对象指针
    std::unordered_map<std::string, llvm::Function *> functions;

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
    std::tuple<llvm::Value *, bool, bool> loopup_variable(std::string name) {
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
    bool declare_variable(std::string name, llvm::Value *var_ptr, bool is_const, bool is_array) {
        if (variables.front().count(name))
            return false;
        variables.front()[name] = std::make_tuple(var_ptr, is_const, is_array);
        return true;
    }
};

#endif // SILLYLANG_CODE_GEN_H
