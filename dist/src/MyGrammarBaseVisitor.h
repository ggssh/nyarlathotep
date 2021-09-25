
// Generated from src/MyGrammar.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "MyGrammarVisitor.h"


/**
 * This class provides an empty implementation of MyGrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MyGrammarBaseVisitor : public MyGrammarVisitor {
public:

  virtual antlrcpp::Any visitAtomExpr(MyGrammarParser::AtomExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenExpr(MyGrammarParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpExpr(MyGrammarParser::OpExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

