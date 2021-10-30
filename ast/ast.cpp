//
// Created by ggssh on 2021/9/30.
//

#include "ast.h"

using namespace nyar::ast;

void CompUnit::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void FuncDef::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void Cond::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void BinopExpr::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void UnaryopExpr::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void LValExpr::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void Number::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void VarDefStmt::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void AssignStmt::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void FuncCallStmt::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void Block::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void IfStmt::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void WhileStmt::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void EmptyStmt::accept(AstVisitor &visitor) {
    visitor.visit(this);
}

void ReturnStmt::accept(AstVisitor &visitor) {
    visitor.visit(this);
}
