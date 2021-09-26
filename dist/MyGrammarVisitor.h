
// Generated from MyGrammar.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "MyGrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MyGrammarParser.
 */
class  MyGrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MyGrammarParser.
   */
    virtual antlrcpp::Any visitAtomExpr(MyGrammarParser::AtomExprContext *context) = 0;

    virtual antlrcpp::Any visitParenExpr(MyGrammarParser::ParenExprContext *context) = 0;

    virtual antlrcpp::Any visitOpExpr(MyGrammarParser::OpExprContext *context) = 0;


};

