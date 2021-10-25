//
// Created by ggssh on 2021/9/30.
//

#ifndef SILLYLANG_AST_BUILDER_H
#define SILLYLANG_AST_BUILDER_H

#include "ast.h"
#include "NyarBaseVisitor.h"
#include "error_reporter.h"

namespace nyar::ast {
    class ASTBuilder : public NyarBaseVisitor {
    public:
        antlrcpp::Any visitCompUnit(NyarParser::CompUnitContext *ctx) override;

        antlrcpp::Any visitDecl(NyarParser::DeclContext *ctx) override;

        antlrcpp::Any visitConstDecl(NyarParser::ConstDeclContext *ctx) override;

        antlrcpp::Any visitConstDef(NyarParser::ConstDefContext *ctx) override;

        antlrcpp::Any visitVarDecl(NyarParser::VarDeclContext *ctx) override;

        antlrcpp::Any visitVarDef(NyarParser::VarDefContext *ctx) override;

        antlrcpp::Any visitFuncDef(NyarParser::FuncDefContext *ctx) override;

        antlrcpp::Any visitBlock(NyarParser::BlockContext *ctx) override;

        antlrcpp::Any visitStmt(NyarParser::StmtContext *ctx) override;

        antlrcpp::Any visitLVal(NyarParser::LValContext *ctx) override;

        antlrcpp::Any visitCond(NyarParser::CondContext *ctx) override;

        antlrcpp::Any visitExpr(NyarParser::ExprContext *ctx) override;

        // override the operator
        ptr<Node> operator()(antlr4::tree::ParseTree *ctx);

        //    ASTBuilder(ErrorReporter &e);

    private:
        //    ErrorReporter &err;
    };
} // namespace silly::ast
#endif // SILLYLANG_AST_BUILDER_H
