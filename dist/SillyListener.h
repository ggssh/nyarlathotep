
// Generated from Silly.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "SillyParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SillyParser.
 */
class  SillyListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterBaseblock(SillyParser::BaseblockContext *ctx) = 0;
  virtual void exitBaseblock(SillyParser::BaseblockContext *ctx) = 0;

  virtual void enterFuncCall(SillyParser::FuncCallContext *ctx) = 0;
  virtual void exitFuncCall(SillyParser::FuncCallContext *ctx) = 0;

  virtual void enterAtomExpr(SillyParser::AtomExprContext *ctx) = 0;
  virtual void exitAtomExpr(SillyParser::AtomExprContext *ctx) = 0;

  virtual void enterParenExpr(SillyParser::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(SillyParser::ParenExprContext *ctx) = 0;

  virtual void enterOpExpr(SillyParser::OpExprContext *ctx) = 0;
  virtual void exitOpExpr(SillyParser::OpExprContext *ctx) = 0;


};

