
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

  virtual void enterBaseblock(SillyParser::BaseblockContext * /*ctx*/) override { }
  virtual void exitBaseblock(SillyParser::BaseblockContext * /*ctx*/) override { }

  virtual void enterFuncCall(SillyParser::FuncCallContext * /*ctx*/) override { }
  virtual void exitFuncCall(SillyParser::FuncCallContext * /*ctx*/) override { }

  virtual void enterAtomExpr(SillyParser::AtomExprContext * /*ctx*/) override { }
  virtual void exitAtomExpr(SillyParser::AtomExprContext * /*ctx*/) override { }

  virtual void enterParenExpr(SillyParser::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(SillyParser::ParenExprContext * /*ctx*/) override { }

  virtual void enterOpExpr(SillyParser::OpExprContext * /*ctx*/) override { }
  virtual void exitOpExpr(SillyParser::OpExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

