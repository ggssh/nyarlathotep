//
// Created by ggssh on 2021/9/30.
//

#ifndef SILLYLANG_AST_H
#define SILLYLANG_AST_H

#include <vector>
#include <memory>
#include <string>

namespace nyar::ast {
    template<typename T>
    using ptr = std::shared_ptr<T>;

// List of reference of type
    template<typename T>
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

    struct Node;
    struct CompUnit;
    struct GlobalDef;
    struct FuncDef;
    struct Cond;
    struct Expr;
    struct BinopExpr;
    struct UnaryopExpr;
    struct LValExpr;
    struct Interger;
    struct Stmt;
    struct VarDefStmt;
    struct AssignStmt;
    struct FuncCallStmt;
    struct Block;
    struct IfStmt;
    struct WhileStmt;
    struct EmptyStmt;
    struct AstVisitor;

// Virtual base of all kinds nodes
    struct Node {
        int line;
        int pos;

        virtual void accept(AstVisitor &visitor) = 0;
    };

// Root node of ordinary ast
    struct CompUnit : Node {
        std::string source_name;
        ptr_list<GlobalDef> global_defs;

        virtual void accept(AstVisitor &visitor) override final;
    };

// Virtual base of global definitions, function or variable one
    struct GlobalDef : virtual Node {
        virtual void accept(AstVisitor &visitor) override = 0;
    };

// 函数定义
    struct FuncDef : GlobalDef {
        std::string name;
        ptr<Block> body;

        virtual void accept(AstVisitor &visitor) override final;
    };

// Condition expression (but not actually treated as expression)
    struct Cond : public Node {
        relop op;
        ptr<Expr> lhs, rhs;

        virtual void accept(AstVisitor &visitor) override final;
    };

// Virtual base of expression
    struct Expr : virtual Node {
        virtual void accept(AstVisitor &visitor) override = 0;
    };

// Binary expression
    struct BinopExpr : Expr {
    public:
        binop op;
        ptr<Expr> lhs, rhs;

        virtual void accept(AstVisitor &visitor) override final;
    };

// Unary expression
    struct UnaryopExpr : public Expr {
    public:
        unaryop op;
        ptr<Expr> rhs;

        virtual void accept(AstVisitor &visitor) override final;
    };

// Expression like 'IDENTIFIER' or 'IDENTIFIER[EXPR]'
    struct LValExpr : public Expr {
    public:
        std::string name;
        // 如果不是数组的话则为空
        ptr<Expr> array_index;

        virtual void accept(AstVisitor &visitor) override final;
    };

// Interger
    struct Interger : public Expr {
    public:
        int number;

        virtual void accept(AstVisitor &visitor) override final;
    };

// Virtual base for statement
    struct Stmt : virtual Node {
    public:
        virtual void accept(AstVisitor &visitor) override = 0;
    };

// Variable definition
// Multiple of this would be both a statement and a global definition
// however, itself only represents a single variable definition
    struct VarDefStmt : Stmt, GlobalDef {
        bool is_constant;
        std::string name;
        ptr<Expr> arr_len;//数组长度
        ptr_list<Expr> initializers;//数组初始化

        virtual void accept(AstVisitor &visitor) override final;
    };

// Assignment statement
    struct AssignStmt : Stmt {
        ptr<LValExpr> target;
        ptr<Expr> value;

        virtual void accept(AstVisitor &visitor) override final;
    };

// 函数调用
    struct FuncCallStmt : Stmt {
        std::string name;

        virtual void accept(AstVisitor &visitor) override final;
    };

// Base of Block
    struct Block : Stmt {
        ptr_list<Stmt> body;

        virtual void accept(AstVisitor &visitor) override final;
    };

// If statement
    struct IfStmt : Stmt {
        ptr<Cond> pred;
        ptr<Stmt> then_body;
        ptr<Stmt> else_body;

        virtual void accept(AstVisitor &visitor) override final;
    };

// While statement
    struct WhileStmt : Stmt {
        ptr<Cond> pred;
        ptr<Stmt> body;

        virtual void accept(AstVisitor &visitor) override final;
    };

// Empty statement (such as a single ';')
    struct EmptyStmt : Stmt {
        virtual void accept(AstVisitor &visitor) override final;
    };

// Visitor base type
    class AstVisitor {
    public:
        virtual void visit(CompUnit *node) = 0;

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

} // namespace silly::ast
#endif // SILLYLANG_AST_H
