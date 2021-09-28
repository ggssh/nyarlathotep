
// Generated from Silly.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "SillyParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SillyParser.
 */
class  SillyVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SillyParser.
   */
    virtual antlrcpp::Any visitBaseblock(SillyParser::BaseblockContext *context) = 0;

    virtual antlrcpp::Any visitFuncCall(SillyParser::FuncCallContext *context) = 0;

    virtual antlrcpp::Any visitAtomExpr(SillyParser::AtomExprContext *context) = 0;

    virtual antlrcpp::Any visitParenExpr(SillyParser::ParenExprContext *context) = 0;

    virtual antlrcpp::Any visitOpExpr(SillyParser::OpExprContext *context) = 0;


};

