//
// Created by ggssh on 2021/9/30.
//

#ifndef SILLYLANG_AST_H
#define SILLYLANG_AST_H

#include <vector>
#include <memory>
#include <string>

namespace ast {
template <typename T>
using ptr = std::shared_ptr<T>;

// List of reference of type
template <typename T>
using ptr_list = std::vector<ptr<T>>;

enum class relop {
    EQ = 0,
    NE,
    LT,
    LE,
    GT,
    GE
};

enum class binop {
    ADD = 0,
    SUB,
    MUL,
    DIV,
    MOD
};

enum class unaryop {
    ADD = 0,
    SUB
};

class Node;
class Assembly;
class GlobalDef;
class FuncDef;
class Cond;
class Expr;
class BinopExpr;
class UnaryopExpr;
class LValExpr;
class Interger;
class Stmt;
class VarDefStmt;
class AssignStmt;
class FuncCallStmt;
class Block;
class IfStmt;
class WhileStmt;
class EmptyStmt;
class AstVisitor;

// Virtual base of all kinds nodes
class Node {
public:
    int line;
    int pos;
    //    virtual void accept
    virtual void accept(AstVisitor &visitor) = 0;
};
// Root node of ordinary ast
class Assembly : public Node {
public:
    ptr_list<GlobalDef> globao_defs;
    virtual void accept(AstVisitor &visitor) override final;
};
// Virtual base of global definitions, function or variable one
class GlobalDef : public Node {
public:
    virtual void accept(AstVisitor &visitor) override = 0;
};
// Function definition
class FuncDef : public GlobalDef {
public:
    std::string name;
    ptr<Block> body;
    virtual void accept(AstVisitor &visitor) override final;
};
// Condition expression (but not actually treated as expression)
class Cond : public Node {
public:
    relop op;
    ptr<Expr> lhs, rhs;
    virtual void accept(AstVisitor &visitor) override final;
};
// Virtual base of expression
class Expr : public Node {
    virtual void accept(AstVisitor &visitor) override = 0;
};
// Binary expression
class BinopExpr : public Expr {
public:
    binop op;
    ptr<Expr> lhs, rhs;
    virtual void accept(AstVisitor &visitor) override final;
};
// Unary expression
class UnaryopExpr : public Expr {
public:
    unaryop op;
    ptr<Expr> rhs;
    virtual void accept(AstVisitor &visitor) override final;
};
// Expression like 'IDENTIFIER' or 'IDENTIFIER[EXPR]'
class LValExpr : public Expr {
public:
    std::string name;
    // nullptr if not indexed as array
    ptr<Expr> array_index;
    virtual void accept(AstVisitor &visitor) override final;
};
// Interger
class Interger : public Expr {
public:
    int number;
    virtual void accept(AstVisitor &visitor) override final;
};
// Virtual base for statement
class Stmt : public Node {
public:
    virtual void accept(AstVisitor &visitor) override = 0;
};
// Variable definition
// Multiple of this would be both a statement and a global definition
// however, itself only represents a single variable definition
class VarDefStmt : public Stmt {
public:
    bool is_constant;
    std::string name;
    ptr<Expr> arr_len;
    ptr_list<Expr> initializers;
    virtual void accept(AstVisitor &visitor) override final;
};
// Assignment statement
class AssignStmt : public Stmt {
public:
    ptr<LValExpr> target;
    ptr<Expr> value;
    virtual void accept(AstVisitor &visitor) override final;
};
// Function call statement
class FuncCallStmt : public Stmt {
public:
    std::string name;
    virtual void accept(AstVisitor &visitor) override final;
};
// Base of Block
class Block : public Stmt {
public:
    ptr_list<Stmt> body;
    virtual void accept(AstVisitor &visitor) override final;
};
// If statement
class IfStmt : public Stmt {
public:
    ptr<Cond> pred;
    ptr<Stmt> then_body;
    ptr<Stmt> else_body;
    virtual void accept(AstVisitor &visitor) override final;
};
// While statement
class WhileStmt : public Stmt {
public:
    ptr<Cond> pred;
    ptr<Stmt> body;
    virtual void accept(AstVisitor &visitor) override final;
};
// Empty statement (such as a single ';')
class EmptyStmt : public Stmt {
public:
    virtual void accept(AstVisitor &visitor) override final;
};

// Visitor base type
class AstVisitor {
public:
    virtual void visit(Assembly *node) = 0;
    virtual void visit(FuncDef *node) = 0;
    virtual void visit(FuncCallStmt *node) = 0;
    virtual void visit(LValExpr *node) = 0;
    virtual void visit(Block *node) = 0;
    virtual void visit(BinopExpr *node) = 0;
    virtual void visit(VarDefStmt *node) = 0;
    virtual void visit(AssignStmt *node) = 0;
    virtual void visit(IfStmt *node) = 0;
    virtual void visit(Interger *node) = 0;
    virtual void visit(WhileStmt *node) = 0;
    virtual void visit(UnaryopExpr *node) = 0;
    virtual void visit(EmptyStmt *node) = 0;
    virtual void visit(Cond *node) = 0;
};

} // namespace ast

#endif // SILLYLANG_AST_H
