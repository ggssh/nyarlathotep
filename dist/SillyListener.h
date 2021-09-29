
// Generated from Silly.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "SillyParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SillyParser.
 */
class  SillyListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompUnit(SillyParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(SillyParser::CompUnitContext *ctx) = 0;

  virtual void enterDecl(SillyParser::DeclContext *ctx) = 0;
  virtual void exitDecl(SillyParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(SillyParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(SillyParser::ConstDeclContext *ctx) = 0;

  virtual void enterBType(SillyParser::BTypeContext *ctx) = 0;
  virtual void exitBType(SillyParser::BTypeContext *ctx) = 0;

  virtual void enterConstDef(SillyParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(SillyParser::ConstDefContext *ctx) = 0;

  virtual void enterConstInitVal(SillyParser::ConstInitValContext *ctx) = 0;
  virtual void exitConstInitVal(SillyParser::ConstInitValContext *ctx) = 0;

  virtual void enterVarDecl(SillyParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(SillyParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef(SillyParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(SillyParser::VarDefContext *ctx) = 0;

  virtual void enterInitVal(SillyParser::InitValContext *ctx) = 0;
  virtual void exitInitVal(SillyParser::InitValContext *ctx) = 0;

  virtual void enterFuncDef(SillyParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(SillyParser::FuncDefContext *ctx) = 0;

  virtual void enterFuncType(SillyParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(SillyParser::FuncTypeContext *ctx) = 0;

  virtual void enterFuncFParams(SillyParser::FuncFParamsContext *ctx) = 0;
  virtual void exitFuncFParams(SillyParser::FuncFParamsContext *ctx) = 0;

  virtual void enterFuncFParam(SillyParser::FuncFParamContext *ctx) = 0;
  virtual void exitFuncFParam(SillyParser::FuncFParamContext *ctx) = 0;

  virtual void enterBlock(SillyParser::BlockContext *ctx) = 0;
  virtual void exitBlock(SillyParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(SillyParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(SillyParser::BlockItemContext *ctx) = 0;

  virtual void enterStmt(SillyParser::StmtContext *ctx) = 0;
  virtual void exitStmt(SillyParser::StmtContext *ctx) = 0;

  virtual void enterExpr(SillyParser::ExprContext *ctx) = 0;
  virtual void exitExpr(SillyParser::ExprContext *ctx) = 0;

  virtual void enterCond(SillyParser::CondContext *ctx) = 0;
  virtual void exitCond(SillyParser::CondContext *ctx) = 0;

  virtual void enterLVal(SillyParser::LValContext *ctx) = 0;
  virtual void exitLVal(SillyParser::LValContext *ctx) = 0;

  virtual void enterPrimaryExp(SillyParser::PrimaryExpContext *ctx) = 0;
  virtual void exitPrimaryExp(SillyParser::PrimaryExpContext *ctx) = 0;

  virtual void enterNumber(SillyParser::NumberContext *ctx) = 0;
  virtual void exitNumber(SillyParser::NumberContext *ctx) = 0;

  virtual void enterUnaryExp(SillyParser::UnaryExpContext *ctx) = 0;
  virtual void exitUnaryExp(SillyParser::UnaryExpContext *ctx) = 0;

  virtual void enterUnaryOp(SillyParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(SillyParser::UnaryOpContext *ctx) = 0;

  virtual void enterFuncRParams(SillyParser::FuncRParamsContext *ctx) = 0;
  virtual void exitFuncRParams(SillyParser::FuncRParamsContext *ctx) = 0;

  virtual void enterMulExp(SillyParser::MulExpContext *ctx) = 0;
  virtual void exitMulExp(SillyParser::MulExpContext *ctx) = 0;

  virtual void enterAddExp(SillyParser::AddExpContext *ctx) = 0;
  virtual void exitAddExp(SillyParser::AddExpContext *ctx) = 0;

  virtual void enterRelExp(SillyParser::RelExpContext *ctx) = 0;
  virtual void exitRelExp(SillyParser::RelExpContext *ctx) = 0;

  virtual void enterEqExp(SillyParser::EqExpContext *ctx) = 0;
  virtual void exitEqExp(SillyParser::EqExpContext *ctx) = 0;

  virtual void enterLAndExp(SillyParser::LAndExpContext *ctx) = 0;
  virtual void exitLAndExp(SillyParser::LAndExpContext *ctx) = 0;

  virtual void enterLOrExp(SillyParser::LOrExpContext *ctx) = 0;
  virtual void exitLOrExp(SillyParser::LOrExpContext *ctx) = 0;

  virtual void enterConstExp(SillyParser::ConstExpContext *ctx) = 0;
  virtual void exitConstExp(SillyParser::ConstExpContext *ctx) = 0;


};

