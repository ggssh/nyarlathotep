
// Generated from Nyar.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "NyarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by NyarParser.
 */
class  NyarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by NyarParser.
   */
    virtual antlrcpp::Any visitCompUnit(NyarParser::CompUnitContext *context) = 0;

    virtual antlrcpp::Any visitDecl(NyarParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitConstDecl(NyarParser::ConstDeclContext *context) = 0;

    virtual antlrcpp::Any visitConstDef(NyarParser::ConstDefContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(NyarParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarDef(NyarParser::VarDefContext *context) = 0;

    virtual antlrcpp::Any visitFuncDef(NyarParser::FuncDefContext *context) = 0;

    virtual antlrcpp::Any visitBlock(NyarParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStmt(NyarParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitLVal(NyarParser::LValContext *context) = 0;

    virtual antlrcpp::Any visitCond(NyarParser::CondContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(NyarParser::RelOpContext *context) = 0;

    virtual antlrcpp::Any visitExpr(NyarParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitBinOp(NyarParser::BinOpContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOp(NyarParser::UnaryOpContext *context) = 0;


};

