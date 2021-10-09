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
//#include <SillyParser.h>

#include "ast.h"
#include "runtime.h"
using namespace llvm;

class CodeGenerator : public silly::ast::AstVisitor {
public:
    void visit(silly::ast::CompUnit *node) override;
    void visit(silly::ast::FuncDef *node) override;
    void visit(silly::ast::FuncCallStmt *node) override;
    void visit(silly::ast::LValExpr *node) override;
    void visit(silly::ast::Block *node) override;
    void visit(silly::ast::BinopExpr *node) override;
    void visit(silly::ast::VarDefStmt *node) override;
    void visit(silly::ast::AssignStmt *node) override;
    void visit(silly::ast::IfStmt *node) override;
    void visit(silly::ast::Interger *node) override;
    void visit(silly::ast::WhileStmt *node) override;
    void visit(silly::ast::UnaryopExpr *node) override;
    void visit(silly::ast::EmptyStmt *node) override;
    void visit(silly::ast::Cond *node) override;

    //    static std::unique_ptr<LLVMContext> TheContext;
    //    static std::unique_ptr<Module> TheMoudule;
    //    static std::unique_ptr<IRBuilder<>> Builder;
    //    static std::map<std::string , Value*> NamedValues;
    llvm::LLVMContext &context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<RuntimeInfo> runtime;

    llvm::Value *value_result;
    int const_result;

    llvm::Function *current_funciton;
    // 统计BaseBlock的数量
    int bb_count;

    bool lval_as_rval;
    bool in_global;
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

    void build(std::string name, std::shared_ptr<silly::ast::Node> tree) {
        // Initialize environment
        module = std::make_unique<llvm::Module>(name, context);
        runtime = std::make_unique<RuntimeInfo>(module.get());

        enter_scope();
        for (auto item : runtime->get_language_symbols()) {
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
    // 变量表
    std::deque<std::unordered_map<std::string, std::tuple<llvm::Value *, bool, bool>>> variables;
    // 函数表
    std::unordered_map<std::string, llvm::Function *> functions;
    void enter_scope() {
        variables.emplace_front();
    }
    void exit_scope() {
        variables.pop_front();
    }
    std::tuple<llvm::Value *, bool, bool> loopup_variable(std::string name) {
        for (auto item : variables) {
            if (item.count(name)) {
                return item[name];
            }
        }
        return std::make_tuple((llvm::Value *)nullptr, false, false);
    }
    bool declare_variable(std::string name, llvm::Value *var_ptr, bool is_const, bool is_array) {
        if (variables.front().count(name))
            return false;
        variables.front()[name] = std::make_tuple(var_ptr, is_const, is_array);
        return true;
    }
};

#endif // SILLYLANG_CODE_GEN_H
