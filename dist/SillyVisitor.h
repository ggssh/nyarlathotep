
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

    virtual antlrcpp::Any visitBType(SillyParser::BTypeContext *context) = 0;

    virtual antlrcpp::Any visitConstDef(SillyParser::ConstDefContext *context) = 0;

    virtual antlrcpp::Any visitConstInitVal(SillyParser::ConstInitValContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(SillyParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarDef(SillyParser::VarDefContext *context) = 0;

    virtual antlrcpp::Any visitInitVal(SillyParser::InitValContext *context) = 0;

    virtual antlrcpp::Any visitFuncDef(SillyParser::FuncDefContext *context) = 0;

    virtual antlrcpp::Any visitFuncType(SillyParser::FuncTypeContext *context) = 0;

    virtual antlrcpp::Any visitFuncFParams(SillyParser::FuncFParamsContext *context) = 0;

    virtual antlrcpp::Any visitFuncFParam(SillyParser::FuncFParamContext *context) = 0;

    virtual antlrcpp::Any visitBlock(SillyParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(SillyParser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitStmt(SillyParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitExpr(SillyParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitCond(SillyParser::CondContext *context) = 0;

    virtual antlrcpp::Any visitLVal(SillyParser::LValContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryExp(SillyParser::PrimaryExpContext *context) = 0;

    virtual antlrcpp::Any visitNumber(SillyParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExp(SillyParser::UnaryExpContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOp(SillyParser::UnaryOpContext *context) = 0;

    virtual antlrcpp::Any visitFuncRParams(SillyParser::FuncRParamsContext *context) = 0;

    virtual antlrcpp::Any visitMulExp(SillyParser::MulExpContext *context) = 0;

    virtual antlrcpp::Any visitAddExp(SillyParser::AddExpContext *context) = 0;

    virtual antlrcpp::Any visitRelExp(SillyParser::RelExpContext *context) = 0;

    virtual antlrcpp::Any visitEqExp(SillyParser::EqExpContext *context) = 0;

    virtual antlrcpp::Any visitLAndExp(SillyParser::LAndExpContext *context) = 0;

    virtual antlrcpp::Any visitLOrExp(SillyParser::LOrExpContext *context) = 0;

    virtual antlrcpp::Any visitConstExp(SillyParser::ConstExpContext *context) = 0;


};

