
// Generated from MyGrammar.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "MyGrammarListener.h"


/**
 * This class provides an empty implementation of MyGrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MyGrammarBaseListener : public MyGrammarListener {
public:

  virtual void enterAtomExpr(MyGrammarParser::AtomExprContext * /*ctx*/) override { }
  virtual void exitAtomExpr(MyGrammarParser::AtomExprContext * /*ctx*/) override { }

  virtual void enterParenExpr(MyGrammarParser::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(MyGrammarParser::ParenExprContext * /*ctx*/) override { }

  virtual void enterOpExpr(MyGrammarParser::OpExprContext * /*ctx*/) override { }
  virtual void exitOpExpr(MyGrammarParser::OpExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

