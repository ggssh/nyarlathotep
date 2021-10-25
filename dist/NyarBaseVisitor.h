
// Generated from Nyar.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "NyarVisitor.h"


/**
 * This class provides an empty implementation of NyarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  NyarBaseVisitor : public NyarVisitor {
public:

  virtual antlrcpp::Any visitCompUnit(NyarParser::CompUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl(NyarParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstDecl(NyarParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstDef(NyarParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(NyarParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDef(NyarParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDef(NyarParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(NyarParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(NyarParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLVal(NyarParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond(NyarParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelOp(NyarParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(NyarParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinOp(NyarParser::BinOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryOp(NyarParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }


};

