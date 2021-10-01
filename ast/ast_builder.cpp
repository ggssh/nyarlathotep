//
// Created by ggssh on 2021/9/30.
//

#include "ast_builder.h"
using namespace ast;

antlrcpp::Any ASTBuilder::visitCompUnit(SillyParser::CompUnitContext *ctx) {
    return SillyBaseVisitor::visitCompUnit(ctx);
}
antlrcpp::Any ASTBuilder::visitDecl(SillyParser::DeclContext *ctx) {
    return SillyBaseVisitor::visitDecl(ctx);
}
antlrcpp::Any ASTBuilder::visitConstDecl(SillyParser::ConstDeclContext *ctx) {
    return SillyBaseVisitor::visitConstDecl(ctx);
}
antlrcpp::Any ASTBuilder::visitConstDef(SillyParser::ConstDefContext *ctx) {
    return SillyBaseVisitor::visitConstDef(ctx);
}
antlrcpp::Any ASTBuilder::visitVarDecl(SillyParser::VarDeclContext *ctx) {
    return SillyBaseVisitor::visitVarDecl(ctx);
}
antlrcpp::Any ASTBuilder::visitVarDef(SillyParser::VarDefContext *ctx) {
    return SillyBaseVisitor::visitVarDef(ctx);
}
antlrcpp::Any ASTBuilder::visitFuncDef(SillyParser::FuncDefContext *ctx) {
    auto result = new FuncDef;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->IDENTIFIER()->getSymbol()->getText();
    auto block = ctx->block();
    result->body.reset(antlr4::tree::AbstractParseTreeVisitor::visit(block).as<Block *>());

    return static_cast<FuncDef *>(result);
    //    return SillyBaseVisitor::visitFuncDef(ctx);
}
antlrcpp::Any ASTBuilder::visitBlock(SillyParser::BlockContext *ctx) {
    //    auto blocks = ctx->blockItem();
    auto ds = ctx->decl();
    auto ss = ctx->stmt();
    auto result = new Block;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    //    result->body = blocks.
    //    for(auto i : blocks){
    //
    //    }
    for (auto i : ds) {
        result->body.push_back(static_cast<std::shared_ptr<Stmt>>(antlr4::tree::AbstractParseTreeVisitor::visit(i).as<Stmt *>()));
    }
    for (auto i : ss) {
        result->body.push_back(static_cast<std::shared_ptr<Stmt>>(antlr4::tree::AbstractParseTreeVisitor::visit(i).as<Stmt *>()));
    }
    //    return SillyBaseVisitor::visitBlock(ctx);
    return static_cast<Stmt *>(result);
}
antlrcpp::Any ASTBuilder::visitStmt(SillyParser::StmtContext *ctx) {
//    return SillyBaseVisitor::visitStmt(ctx);
    // lVal ASSIGN expr SEMICOLON
    if(ctx->ASSIGN()){

    }
}
antlrcpp::Any ASTBuilder::visitLVal(SillyParser::LValContext *ctx) {
    auto result = new LValExpr;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->IDENTIFIER()->getSymbol()->getText();
    //    result->name = ctx->IDENTIFIER()->getText();
    if (ctx->expr()) {
        auto expressions = ctx->expr();
        result->array_index.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions).as<Expr *>());
    } else {
        result->array_index = nullptr;
    }
    return static_cast<LValExpr *>(result);
    //    return SillyBaseVisitor::visitLVal(ctx);
}
antlrcpp::Any ASTBuilder::visitCond(SillyParser::CondContext *ctx) {
    auto expressions = ctx->expr();
    auto result = new Cond;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->lhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions[0]).as<Expr *>());
    auto ro = ctx->relOp();
    if (ro->EQ())
        result->op = relop::EQ;
    else if (ro->NE())
        result->op = relop::NE;
    else if (ro->LT())
        result->op = relop::LT;
    else if (ro->LE())
        result->op = relop::LE;
    else if (ro->GT())
        result->op = relop::GT;
    else if (ro->GE())
        result->op = relop::GE;
    result->rhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions[1]).as<Expr *>());
    return static_cast<Cond *>(result);
    //    return SillyBaseVisitor::visitCond(ctx);
}
antlrcpp::Any ASTBuilder::visitExpr(SillyParser::ExprContext *ctx) {
    //    return SillyBaseVisitor::visitExpr(ctx);
    // Get all sub-contexts of type "expr"
    auto expressions = ctx->expr();
    // The size of expression is two indicates that it's an expression of binary operator
    if (expressions.size() == 2) {
        auto result = new BinopExpr;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->lhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions[0]).as<Expr *>());
        auto bo = ctx->binOp();
        //        if (ctx->binOp())
        if (bo->ADD())
            result->op = binop::ADD;
        else if (bo->SUB())
            result->op = binop::SUB;
        else if (bo->MUL())
            result->op = binop::MUL;
        else if (bo->DIV())
            result->op = binop::DIV;
        else if (bo->MOD())
            result->op = binop::MOD;
        result->rhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions[1]).as<Expr *>());
    } else if (expressions.size() == 1) {
        // If is has unaryOp , it must be a unaryExpr else it must have two parens
        if (ctx->unaryOp()) {
            auto result = new UnaryopExpr;
            result->line = ctx->getStart()->getLine();
            result->pos = ctx->getStart()->getCharPositionInLine();
            auto uo = ctx->unaryOp();
            if (uo->ADD())
                result->op = unaryop::ADD;
            if (uo->SUB())
                result->op = unaryop::SUB;
            result->rhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions[0]).as<Expr *>());
            return static_cast<Expr *>(result);
        } else {
            if (ctx->LPAREN())
                return antlr4::tree::AbstractParseTreeVisitor::visit(expressions[0]);
        }
    } else {
        auto result = new Interger;
        auto number = ctx->NUMBER();
        // If `Number` exists as a child, we can say it's a literal integer expression.
        result->line = number->getSymbol()->getLine();
        result->pos = number->getSymbol()->getCharPositionInLine();
        auto text = number->getSymbol()->getText();
        // consider to enable 0x
        result->number = std::stoi(text, nullptr, 10);
        return static_cast<Expr *>(result);
    }
}
ast::ptr<ast::Node> ASTBuilder::operator()(antlr4::tree::ParseTree *ctx) {
    auto result = antlr4::tree::AbstractParseTreeVisitor::visit(ctx);
    if (result.is<Node *>())
        return ptr<Node>(result.as<Node *>());
    //    return ast::ptr<ast::Node>();
    if (result.is<Assembly *>())
        return ptr<Node>(result.as<Assembly *>());
    if (result.is<GlobalDef *>())
        return ptr<Node>(result.as<GlobalDef *>());
    if (result.is<FuncDef *>())
        return ptr<Node>(result.as<FuncDef *>());
    if (result.is<Cond *>())
        return ptr<Node>(result.as<Cond *>());
    if (result.is<Expr *>())
        return ptr<Node>(result.as<Expr *>());
    if (result.is<BinopExpr *>())
        return ptr<Node>(result.as<BinopExpr *>());
    if (result.is<UnaryopExpr *>())
        return ptr<Node>(result.as<UnaryopExpr *>());
    if (result.is<LValExpr *>())
        return ptr<Node>(result.as<LValExpr *>());
    if (result.is<Interger *>())
        return ptr<Node>(result.as<Interger *>());
    if (result.is<Stmt *>())
        return ptr<Node>(result.as<Stmt *>());
    if (result.is<VarDefStmt *>())
        return ptr<Node>(result.as<VarDefStmt *>());
    if (result.is<AssignStmt *>())
        return ptr<Node>(result.as<AssignStmt *>());
    if (result.is<FuncCallStmt *>())
        return ptr<Node>(result.as<FuncCallStmt *>());
    if (result.is<Block *>())
        return ptr<Node>(result.as<Block *>());
    if (result.is<IfStmt *>())
        return ptr<Node>(result.as<IfStmt *>());
    if (result.is<WhileStmt *>())
        return ptr<Node>(result.as<WhileStmt *>());
    return nullptr;
}
