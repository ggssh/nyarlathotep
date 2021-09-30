
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

  virtual void enterConstDef(SillyParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(SillyParser::ConstDefContext *ctx) = 0;

  virtual void enterVarDecl(SillyParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(SillyParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef(SillyParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(SillyParser::VarDefContext *ctx) = 0;

  virtual void enterFuncDef(SillyParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(SillyParser::FuncDefContext *ctx) = 0;

  virtual void enterBlock(SillyParser::BlockContext *ctx) = 0;
  virtual void exitBlock(SillyParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(SillyParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(SillyParser::BlockItemContext *ctx) = 0;

  virtual void enterStmt(SillyParser::StmtContext *ctx) = 0;
  virtual void exitStmt(SillyParser::StmtContext *ctx) = 0;

  virtual void enterLVal(SillyParser::LValContext *ctx) = 0;
  virtual void exitLVal(SillyParser::LValContext *ctx) = 0;

  virtual void enterCond(SillyParser::CondContext *ctx) = 0;
  virtual void exitCond(SillyParser::CondContext *ctx) = 0;

  virtual void enterRelOp(SillyParser::RelOpContext *ctx) = 0;
  virtual void exitRelOp(SillyParser::RelOpContext *ctx) = 0;

  virtual void enterExpr(SillyParser::ExprContext *ctx) = 0;
  virtual void exitExpr(SillyParser::ExprContext *ctx) = 0;

  virtual void enterBinOp(SillyParser::BinOpContext *ctx) = 0;
  virtual void exitBinOp(SillyParser::BinOpContext *ctx) = 0;

  virtual void enterUnaryOp(SillyParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(SillyParser::UnaryOpContext *ctx) = 0;


};

