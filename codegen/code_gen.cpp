//
// Created by ggssh on 2021/10/9 0009.
//

#include "code_gen.h"
#include <vector>

using namespace llvm;

void CodeGenerator::visit(nyar::ast::CompUnit *node) {
    in_global = true;
    //随机初始化避免段错误
    value_result = ConstantInt::get(Type::getInt32Ty(context), 666);
    bb_count = 1;
    for (const auto &ptr_def: node->global_defs) {
        ptr_def->accept(*this);
    }
}

void CodeGenerator::visit(nyar::ast::FuncDef *node) {
    //    FunctionType *FT = FunctionType::get(Type::getVoidTy(*TheContext), false);
    // 使用module.get()来获取module的指针,否则会引起unique_ptr的deconstruction
    //    Function *F = Function::Create(FT,Function::ExternalLinkage,node->name,TheMoudule.get());
    //    Function *F = Function::Create()
    in_global = false;
    if (functions.find(node->name) == functions.end()) {
        // todo 错误处理
    }
//    Function *f = Function::Create(FunctionType::get(Type::getVoidTy(context),std::ve))
}

void CodeGenerator::visit(nyar::ast::FuncCallStmt *node) {
}

void CodeGenerator::visit(nyar::ast::LValExpr *node) {
}

void CodeGenerator::visit(nyar::ast::Block *node) {
}

void CodeGenerator::visit(nyar::ast::BinopExpr *node) {
}

void CodeGenerator::visit(nyar::ast::VarDefStmt *node) {
}

void CodeGenerator::visit(nyar::ast::AssignStmt *node) {
}

void CodeGenerator::visit(nyar::ast::IfStmt *node) {
}

void CodeGenerator::visit(nyar::ast::Interger *node) {
}

void CodeGenerator::visit(nyar::ast::WhileStmt *node) {
}

void CodeGenerator::visit(nyar::ast::UnaryopExpr *node) {
}

void CodeGenerator::visit(nyar::ast::EmptyStmt *node) {
}

void CodeGenerator::visit(nyar::ast::Cond *node) {
}
