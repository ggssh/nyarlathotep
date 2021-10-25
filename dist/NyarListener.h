
// Generated from Nyar.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "NyarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by NyarParser.
 */
class  NyarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompUnit(NyarParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(NyarParser::CompUnitContext *ctx) = 0;

  virtual void enterDecl(NyarParser::DeclContext *ctx) = 0;
  virtual void exitDecl(NyarParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(NyarParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(NyarParser::ConstDeclContext *ctx) = 0;

  virtual void enterConstDef(NyarParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(NyarParser::ConstDefContext *ctx) = 0;

  virtual void enterVarDecl(NyarParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(NyarParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef(NyarParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(NyarParser::VarDefContext *ctx) = 0;

  virtual void enterFuncDef(NyarParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(NyarParser::FuncDefContext *ctx) = 0;

  virtual void enterBlock(NyarParser::BlockContext *ctx) = 0;
  virtual void exitBlock(NyarParser::BlockContext *ctx) = 0;

  virtual void enterStmt(NyarParser::StmtContext *ctx) = 0;
  virtual void exitStmt(NyarParser::StmtContext *ctx) = 0;

  virtual void enterLVal(NyarParser::LValContext *ctx) = 0;
  virtual void exitLVal(NyarParser::LValContext *ctx) = 0;

  virtual void enterCond(NyarParser::CondContext *ctx) = 0;
  virtual void exitCond(NyarParser::CondContext *ctx) = 0;

  virtual void enterRelOp(NyarParser::RelOpContext *ctx) = 0;
  virtual void exitRelOp(NyarParser::RelOpContext *ctx) = 0;

  virtual void enterExpr(NyarParser::ExprContext *ctx) = 0;
  virtual void exitExpr(NyarParser::ExprContext *ctx) = 0;

  virtual void enterBinOp(NyarParser::BinOpContext *ctx) = 0;
  virtual void exitBinOp(NyarParser::BinOpContext *ctx) = 0;

  virtual void enterUnaryOp(NyarParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(NyarParser::UnaryOpContext *ctx) = 0;


};

