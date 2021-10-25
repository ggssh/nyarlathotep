
// Generated from Nyar.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "NyarListener.h"


/**
 * This class provides an empty implementation of NyarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  NyarBaseListener : public NyarListener {
public:

  virtual void enterCompUnit(NyarParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(NyarParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterDecl(NyarParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(NyarParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(NyarParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(NyarParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterConstDef(NyarParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(NyarParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterVarDecl(NyarParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(NyarParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDef(NyarParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(NyarParser::VarDefContext * /*ctx*/) override { }

  virtual void enterFuncDef(NyarParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(NyarParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterBlock(NyarParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(NyarParser::BlockContext * /*ctx*/) override { }

  virtual void enterStmt(NyarParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(NyarParser::StmtContext * /*ctx*/) override { }

  virtual void enterLVal(NyarParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(NyarParser::LValContext * /*ctx*/) override { }

  virtual void enterCond(NyarParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(NyarParser::CondContext * /*ctx*/) override { }

  virtual void enterRelOp(NyarParser::RelOpContext * /*ctx*/) override { }
  virtual void exitRelOp(NyarParser::RelOpContext * /*ctx*/) override { }

  virtual void enterExpr(NyarParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(NyarParser::ExprContext * /*ctx*/) override { }

  virtual void enterBinOp(NyarParser::BinOpContext * /*ctx*/) override { }
  virtual void exitBinOp(NyarParser::BinOpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(NyarParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(NyarParser::UnaryOpContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

