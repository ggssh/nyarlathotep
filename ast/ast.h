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

    class Node;

    class CompUnit;

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

// 所有类的基类
    class Node {
    public:
        int line;
        int pos;

        virtual void accept(AstVisitor &visitor) = 0;
    };

// 语法树的根节点
    class CompUnit : public Node {
    public:
        ptr_list<Node> body;

        void accept(AstVisitor &visitor) final;
    };

// Virtual base of global definitions, function or variable one
//    class GlobalDef : virtual Node {
//        virtual void accept(AstVisitor &visitor) override = 0;
//    };

// 函数定义
    class FuncDef : public Node {
    public:
        std::string name;
        ptr<Block> body;

        void accept(AstVisitor &visitor) final;
    };

// Condition expression (but not actually treated as expression)
    class Cond : public Node {
    public:
        relop op;
        ptr<Expr> lhs, rhs;

        void accept(AstVisitor &visitor) final;
    };

// 表达式基类
    class Expr : public Node {
    public:
        void accept(AstVisitor &visitor) override = 0;
    };

// 二元表达式
    class BinopExpr : public Expr {
    public:
        binop op;
        ptr<Expr> lhs, rhs;

        void accept(AstVisitor &visitor) final;
    };

// 一元表达式
    class UnaryopExpr : public Expr {
    public:
        unaryop op;
        ptr<Expr> rhs;

        void accept(AstVisitor &visitor) final;
    };

// 左值表达式
    class LValExpr : public Expr {
    public:
        std::string name;
        // 如果不是数组的话则为空
        ptr<Expr> arr_index;

        void accept(AstVisitor &visitor) final;
    };

// 数值
    class Number : public Expr {
    public:
        int number = 0;

        void accept(AstVisitor &visitor) final;
    };

// 语句基类
    class Stmt : public Node {
    public:
        void accept(AstVisitor &visitor) override = 0;
    };

// Variable definition
// Multiple of this would be both a statement and a global definition
// however, itself only represents a single variable definition

// 将Define和Declaration合到一起,在分析声明的过程中进行define的分析
    class VarDefStmt : public Stmt {
    public:
        bool is_const;
        std::string name;
        // 如果
        ptr<Expr> arr_length;//数组长度
        ptr_list<Expr> init_value;//数组初始化

        void accept(AstVisitor &visitor) final;
    };

// Assignment statement
    class AssignStmt : public Stmt {
    public:
        ptr<LValExpr> lhs;//左值
        ptr<Expr> rhs;//右值

        void accept(AstVisitor &visitor) final;
    };

// 函数调用
    class FuncCallStmt : public Stmt {
    public:
        std::string name;

        void accept(AstVisitor &visitor) final;
    };

// Base of Block
    class Block : public Stmt {
    public:
        ptr_list<Stmt> body;

        void accept(AstVisitor &visitor) final;
    };

// If else 语句
    class IfStmt : public Stmt {
    public:
        ptr<Cond> cond;
        ptr<Stmt> then_body;
        ptr<Stmt> else_body;

        void accept(AstVisitor &visitor) final;
    };

// While 语句
    class WhileStmt : public Stmt {
    public:
        ptr<Cond> cond;
        ptr<Stmt> do_body;

        void accept(AstVisitor &visitor) final;
    };

// 空语句(只有一个 ';')
    class EmptyStmt : public Stmt {
    public:
        void accept(AstVisitor &visitor) final;
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

        virtual void visit(Number *node) = 0;

        virtual void visit(WhileStmt *node) = 0;

        virtual void visit(UnaryopExpr *node) = 0;

        virtual void visit(EmptyStmt *node) = 0;

        virtual void visit(Cond *node) = 0;
    };

} // namespace silly::ast
#endif // SILLYLANG_AST_H
