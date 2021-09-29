
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

  virtual void enterBType(SillyParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(SillyParser::BTypeContext * /*ctx*/) override { }

  virtual void enterConstDef(SillyParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(SillyParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterConstInitVal(SillyParser::ConstInitValContext * /*ctx*/) override { }
  virtual void exitConstInitVal(SillyParser::ConstInitValContext * /*ctx*/) override { }

  virtual void enterVarDecl(SillyParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(SillyParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDef(SillyParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(SillyParser::VarDefContext * /*ctx*/) override { }

  virtual void enterInitVal(SillyParser::InitValContext * /*ctx*/) override { }
  virtual void exitInitVal(SillyParser::InitValContext * /*ctx*/) override { }

  virtual void enterFuncDef(SillyParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(SillyParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFuncType(SillyParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(SillyParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterFuncFParams(SillyParser::FuncFParamsContext * /*ctx*/) override { }
  virtual void exitFuncFParams(SillyParser::FuncFParamsContext * /*ctx*/) override { }

  virtual void enterFuncFParam(SillyParser::FuncFParamContext * /*ctx*/) override { }
  virtual void exitFuncFParam(SillyParser::FuncFParamContext * /*ctx*/) override { }

  virtual void enterBlock(SillyParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(SillyParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(SillyParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(SillyParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterStmt(SillyParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(SillyParser::StmtContext * /*ctx*/) override { }

  virtual void enterExpr(SillyParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(SillyParser::ExprContext * /*ctx*/) override { }

  virtual void enterCond(SillyParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(SillyParser::CondContext * /*ctx*/) override { }

  virtual void enterLVal(SillyParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(SillyParser::LValContext * /*ctx*/) override { }

  virtual void enterPrimaryExp(SillyParser::PrimaryExpContext * /*ctx*/) override { }
  virtual void exitPrimaryExp(SillyParser::PrimaryExpContext * /*ctx*/) override { }

  virtual void enterNumber(SillyParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(SillyParser::NumberContext * /*ctx*/) override { }

  virtual void enterUnaryExp(SillyParser::UnaryExpContext * /*ctx*/) override { }
  virtual void exitUnaryExp(SillyParser::UnaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(SillyParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(SillyParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterFuncRParams(SillyParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(SillyParser::FuncRParamsContext * /*ctx*/) override { }

  virtual void enterMulExp(SillyParser::MulExpContext * /*ctx*/) override { }
  virtual void exitMulExp(SillyParser::MulExpContext * /*ctx*/) override { }

  virtual void enterAddExp(SillyParser::AddExpContext * /*ctx*/) override { }
  virtual void exitAddExp(SillyParser::AddExpContext * /*ctx*/) override { }

  virtual void enterRelExp(SillyParser::RelExpContext * /*ctx*/) override { }
  virtual void exitRelExp(SillyParser::RelExpContext * /*ctx*/) override { }

  virtual void enterEqExp(SillyParser::EqExpContext * /*ctx*/) override { }
  virtual void exitEqExp(SillyParser::EqExpContext * /*ctx*/) override { }

  virtual void enterLAndExp(SillyParser::LAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExp(SillyParser::LAndExpContext * /*ctx*/) override { }

  virtual void enterLOrExp(SillyParser::LOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExp(SillyParser::LOrExpContext * /*ctx*/) override { }

  virtual void enterConstExp(SillyParser::ConstExpContext * /*ctx*/) override { }
  virtual void exitConstExp(SillyParser::ConstExpContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

