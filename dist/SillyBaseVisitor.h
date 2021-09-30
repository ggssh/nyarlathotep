
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

  virtual antlrcpp::Any visitCompUnit(SillyParser::CompUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl(SillyParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstDecl(SillyParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstDef(SillyParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(SillyParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar(SillyParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDef(SillyParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(SillyParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockItem(SillyParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(SillyParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLVal(SillyParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond(SillyParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelOp(SillyParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(SillyParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinOp(SillyParser::BinOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryOp(SillyParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }


};

