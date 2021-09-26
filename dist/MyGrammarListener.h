
// Generated from MyGrammar.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "MyGrammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MyGrammarParser.
 */
class  MyGrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAtomExpr(MyGrammarParser::AtomExprContext *ctx) = 0;
  virtual void exitAtomExpr(MyGrammarParser::AtomExprContext *ctx) = 0;

  virtual void enterParenExpr(MyGrammarParser::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(MyGrammarParser::ParenExprContext *ctx) = 0;

  virtual void enterOpExpr(MyGrammarParser::OpExprContext *ctx) = 0;
  virtual void exitOpExpr(MyGrammarParser::OpExprContext *ctx) = 0;


};

