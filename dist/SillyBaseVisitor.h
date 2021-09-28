
// Generated from Silly.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "SillyVisitor.h"


/**
 * This class provides an empty implementation of SillyVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SillyBaseVisitor : public SillyVisitor {
public:

  virtual antlrcpp::Any visitBaseblock(SillyParser::BaseblockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCall(SillyParser::FuncCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomExpr(SillyParser::AtomExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenExpr(SillyParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpExpr(SillyParser::OpExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

