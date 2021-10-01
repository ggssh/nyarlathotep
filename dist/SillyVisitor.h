
// Generated from Silly.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "SillyParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SillyParser.
 */
class  SillyVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SillyParser.
   */
    virtual antlrcpp::Any visitCompUnit(SillyParser::CompUnitContext *context) = 0;

    virtual antlrcpp::Any visitDecl(SillyParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitConstDecl(SillyParser::ConstDeclContext *context) = 0;

    virtual antlrcpp::Any visitConstDef(SillyParser::ConstDefContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(SillyParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarDef(SillyParser::VarDefContext *context) = 0;

    virtual antlrcpp::Any visitFuncDef(SillyParser::FuncDefContext *context) = 0;

    virtual antlrcpp::Any visitBlock(SillyParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStmt(SillyParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitLVal(SillyParser::LValContext *context) = 0;

    virtual antlrcpp::Any visitCond(SillyParser::CondContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(SillyParser::RelOpContext *context) = 0;

    virtual antlrcpp::Any visitExpr(SillyParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitBinOp(SillyParser::BinOpContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOp(SillyParser::UnaryOpContext *context) = 0;


};

