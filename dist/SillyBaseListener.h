
// Generated from Silly.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "SillyListener.h"


/**
 * This class provides an empty implementation of SillyListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SillyBaseListener : public SillyListener {
public:

  virtual void enterCompUnit(SillyParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(SillyParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterDecl(SillyParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(SillyParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(SillyParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(SillyParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterConstDef(SillyParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(SillyParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterVarDecl(SillyParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(SillyParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDef(SillyParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(SillyParser::VarDefContext * /*ctx*/) override { }

  virtual void enterFuncDef(SillyParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(SillyParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterBlock(SillyParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(SillyParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(SillyParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(SillyParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterStmt(SillyParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(SillyParser::StmtContext * /*ctx*/) override { }

  virtual void enterLVal(SillyParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(SillyParser::LValContext * /*ctx*/) override { }

  virtual void enterCond(SillyParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(SillyParser::CondContext * /*ctx*/) override { }

  virtual void enterRelOp(SillyParser::RelOpContext * /*ctx*/) override { }
  virtual void exitRelOp(SillyParser::RelOpContext * /*ctx*/) override { }

  virtual void enterExpr(SillyParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(SillyParser::ExprContext * /*ctx*/) override { }

  virtual void enterBinOp(SillyParser::BinOpContext * /*ctx*/) override { }
  virtual void exitBinOp(SillyParser::BinOpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(SillyParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(SillyParser::UnaryOpContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

