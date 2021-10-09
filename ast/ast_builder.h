//
// Created by ggssh on 2021/9/30.
//

#ifndef SILLYLANG_AST_BUILDER_H
#define SILLYLANG_AST_BUILDER_H

#include "ast.h"
#include "SillyBaseVisitor.h"

namespace silly::ast {
class ASTBuilder : public SillyBaseVisitor {
public:
    antlrcpp::Any visitCompUnit(SillyParser::CompUnitContext *ctx) override;
    antlrcpp::Any visitDecl(SillyParser::DeclContext *ctx) override;
    antlrcpp::Any visitConstDecl(SillyParser::ConstDeclContext *ctx) override;
    antlrcpp::Any visitConstDef(SillyParser::ConstDefContext *ctx) override;
    antlrcpp::Any visitVarDecl(SillyParser::VarDeclContext *ctx) override;
    antlrcpp::Any visitVarDef(SillyParser::VarDefContext *ctx) override;
    antlrcpp::Any visitFuncDef(SillyParser::FuncDefContext *ctx) override;
    antlrcpp::Any visitBlock(SillyParser::BlockContext *ctx) override;
    antlrcpp::Any visitStmt(SillyParser::StmtContext *ctx) override;
    antlrcpp::Any visitLVal(SillyParser::LValContext *ctx) override;
    antlrcpp::Any visitCond(SillyParser::CondContext *ctx) override;
    antlrcpp::Any visitExpr(SillyParser::ExprContext *ctx) override;

    // override the operator
    ptr<Node> operator()(antlr4::tree::ParseTree *ctx);
};
} // namespace silly::ast
#endif // SILLYLANG_AST_BUILDER_H
