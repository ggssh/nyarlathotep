//
// Created by ggssh on 2021/9/30.
//

#ifndef SILLYLANG_AST_BUILDER_H
#define SILLYLANG_AST_BUILDER_H

#include "ast.h"
#include "SillyBaseVisitor.h"

namespace silly {
namespace ast {
class ASTBuilder : public SillyBaseVisitor {
public:
    virtual antlrcpp::Any visitCompUnit(SillyParser::CompUnitContext *ctx) override;
    virtual antlrcpp::Any visitDecl(SillyParser::DeclContext *ctx) override;
    virtual antlrcpp::Any visitConstDecl(SillyParser::ConstDeclContext *ctx) override;
    virtual antlrcpp::Any visitConstDef(SillyParser::ConstDefContext *ctx) override;
    virtual antlrcpp::Any visitVarDecl(SillyParser::VarDeclContext *ctx) override;
    virtual antlrcpp::Any visitVarDef(SillyParser::VarDefContext *ctx) override;
    virtual antlrcpp::Any visitFuncDef(SillyParser::FuncDefContext *ctx) override;
    virtual antlrcpp::Any visitBlock(SillyParser::BlockContext *ctx) override;
    virtual antlrcpp::Any visitStmt(SillyParser::StmtContext *ctx) override;
    virtual antlrcpp::Any visitLVal(SillyParser::LValContext *ctx) override;
    virtual antlrcpp::Any visitCond(SillyParser::CondContext *ctx) override;
    virtual antlrcpp::Any visitExpr(SillyParser::ExprContext *ctx) override;

    ptr<Node> operator()(antlr4::tree::ParseTree *ctx);
};
} // end of namespace ast
} // end of namespace silly
#endif // SILLYLANG_AST_BUILDER_H
