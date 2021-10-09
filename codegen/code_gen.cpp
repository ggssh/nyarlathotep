//
// Created by ggssh on 2021/10/9 0009.
//

#include "code_gen.h"
#include <vector>

using namespace llvm;

void CodeGenerator::visit(silly::ast::CompUnit *node) {
}
void CodeGenerator::visit(silly::ast::FuncDef *node) {
    //    FunctionType *FT = FunctionType::get(Type::getVoidTy(*TheContext), false);
    // 使用module.get()来获取module的指针,否则会引起unique_ptr的deconstruction
    //    Function *F = Function::Create(FT,Function::ExternalLinkage,node->name,TheMoudule.get());
    //    Function *F = Function::Create()
}
void CodeGenerator::visit(silly::ast::FuncCallStmt *node) {
}
void CodeGenerator::visit(silly::ast::LValExpr *node) {
}
void CodeGenerator::visit(silly::ast::Block *node) {
}
void CodeGenerator::visit(silly::ast::BinopExpr *node) {
}
void CodeGenerator::visit(silly::ast::VarDefStmt *node) {
}
void CodeGenerator::visit(silly::ast::AssignStmt *node) {
}
void CodeGenerator::visit(silly::ast::IfStmt *node) {
}
void CodeGenerator::visit(silly::ast::Interger *node) {
}
void CodeGenerator::visit(silly::ast::WhileStmt *node) {
}
void CodeGenerator::visit(silly::ast::UnaryopExpr *node) {
}
void CodeGenerator::visit(silly::ast::EmptyStmt *node) {
}
void CodeGenerator::visit(silly::ast::Cond *node) {
}
