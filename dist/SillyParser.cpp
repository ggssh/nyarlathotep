
// Generated from Silly.g4 by ANTLR 4.9


#include "SillyListener.h"
#include "SillyVisitor.h"

#include "SillyParser.h"


using namespace antlrcpp;
using namespace antlr4;

SillyParser::SillyParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SillyParser::~SillyParser() {
  delete _interpreter;
}

std::string SillyParser::getGrammarFileName() const {
  return "Silly.g4";
}

const std::vector<std::string>& SillyParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SillyParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

SillyParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::CompUnitContext::EOF() {
  return getToken(SillyParser::EOF, 0);
}

std::vector<SillyParser::DeclContext *> SillyParser::CompUnitContext::decl() {
  return getRuleContexts<SillyParser::DeclContext>();
}

SillyParser::DeclContext* SillyParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<SillyParser::DeclContext>(i);
}

std::vector<SillyParser::FuncDefContext *> SillyParser::CompUnitContext::funcDef() {
  return getRuleContexts<SillyParser::FuncDefContext>();
}

SillyParser::FuncDefContext* SillyParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<SillyParser::FuncDefContext>(i);
}


size_t SillyParser::CompUnitContext::getRuleIndex() const {
  return SillyParser::RuleCompUnit;
}

void SillyParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void SillyParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}


antlrcpp::Any SillyParser::CompUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitCompUnit(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::CompUnitContext* SillyParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, SillyParser::RuleCompUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SillyParser::INT)
      | (1ULL << SillyParser::VOID)
      | (1ULL << SillyParser::CONST))) != 0)) {
      setState(64);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(62);
        decl();
        break;
      }

      case 2: {
        setState(63);
        funcDef();
        break;
      }

      default:
        break;
      }
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69);
    match(SillyParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

SillyParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::ConstDeclContext* SillyParser::DeclContext::constDecl() {
  return getRuleContext<SillyParser::ConstDeclContext>(0);
}

SillyParser::VarDeclContext* SillyParser::DeclContext::varDecl() {
  return getRuleContext<SillyParser::VarDeclContext>(0);
}


size_t SillyParser::DeclContext::getRuleIndex() const {
  return SillyParser::RuleDecl;
}

void SillyParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void SillyParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


antlrcpp::Any SillyParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::DeclContext* SillyParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, SillyParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SillyParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(71);
        constDecl();
        break;
      }

      case SillyParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(72);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

SillyParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::ConstDeclContext::CONST() {
  return getToken(SillyParser::CONST, 0);
}

SillyParser::BTypeContext* SillyParser::ConstDeclContext::bType() {
  return getRuleContext<SillyParser::BTypeContext>(0);
}

std::vector<SillyParser::ConstDefContext *> SillyParser::ConstDeclContext::constDef() {
  return getRuleContexts<SillyParser::ConstDefContext>();
}

SillyParser::ConstDefContext* SillyParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<SillyParser::ConstDefContext>(i);
}

tree::TerminalNode* SillyParser::ConstDeclContext::SEM() {
  return getToken(SillyParser::SEM, 0);
}

tree::TerminalNode* SillyParser::ConstDeclContext::COMMA() {
  return getToken(SillyParser::COMMA, 0);
}


size_t SillyParser::ConstDeclContext::getRuleIndex() const {
  return SillyParser::RuleConstDecl;
}

void SillyParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void SillyParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}


antlrcpp::Any SillyParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::ConstDeclContext* SillyParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, SillyParser::RuleConstDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    match(SillyParser::CONST);
    setState(76);
    bType();
    setState(77);
    constDef();

    setState(78);
    match(SillyParser::COMMA);
    setState(79);
    constDef();
    setState(81);
    match(SillyParser::SEM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

SillyParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::BTypeContext::INT() {
  return getToken(SillyParser::INT, 0);
}


size_t SillyParser::BTypeContext::getRuleIndex() const {
  return SillyParser::RuleBType;
}

void SillyParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void SillyParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}


antlrcpp::Any SillyParser::BTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitBType(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::BTypeContext* SillyParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, SillyParser::RuleBType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(SillyParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

SillyParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::ConstDefContext::IDENTIFIER() {
  return getToken(SillyParser::IDENTIFIER, 0);
}

tree::TerminalNode* SillyParser::ConstDefContext::ASSIGN() {
  return getToken(SillyParser::ASSIGN, 0);
}

SillyParser::ConstInitValContext* SillyParser::ConstDefContext::constInitVal() {
  return getRuleContext<SillyParser::ConstInitValContext>(0);
}

tree::TerminalNode* SillyParser::ConstDefContext::LBRACK() {
  return getToken(SillyParser::LBRACK, 0);
}

SillyParser::ConstExpContext* SillyParser::ConstDefContext::constExp() {
  return getRuleContext<SillyParser::ConstExpContext>(0);
}

tree::TerminalNode* SillyParser::ConstDefContext::RBRACK() {
  return getToken(SillyParser::RBRACK, 0);
}


size_t SillyParser::ConstDefContext::getRuleIndex() const {
  return SillyParser::RuleConstDef;
}

void SillyParser::ConstDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDef(this);
}

void SillyParser::ConstDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDef(this);
}


antlrcpp::Any SillyParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::ConstDefContext* SillyParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, SillyParser::RuleConstDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(SillyParser::IDENTIFIER);

    setState(86);
    match(SillyParser::LBRACK);
    setState(87);
    constExp();
    setState(88);
    match(SillyParser::RBRACK);
    setState(90);
    match(SillyParser::ASSIGN);
    setState(91);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

SillyParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::ConstExpContext* SillyParser::ConstInitValContext::constExp() {
  return getRuleContext<SillyParser::ConstExpContext>(0);
}

tree::TerminalNode* SillyParser::ConstInitValContext::LBRACE() {
  return getToken(SillyParser::LBRACE, 0);
}

tree::TerminalNode* SillyParser::ConstInitValContext::RBRACE() {
  return getToken(SillyParser::RBRACE, 0);
}

std::vector<SillyParser::ConstInitValContext *> SillyParser::ConstInitValContext::constInitVal() {
  return getRuleContexts<SillyParser::ConstInitValContext>();
}

SillyParser::ConstInitValContext* SillyParser::ConstInitValContext::constInitVal(size_t i) {
  return getRuleContext<SillyParser::ConstInitValContext>(i);
}

tree::TerminalNode* SillyParser::ConstInitValContext::COMMA() {
  return getToken(SillyParser::COMMA, 0);
}


size_t SillyParser::ConstInitValContext::getRuleIndex() const {
  return SillyParser::RuleConstInitVal;
}

void SillyParser::ConstInitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitVal(this);
}

void SillyParser::ConstInitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitVal(this);
}


antlrcpp::Any SillyParser::ConstInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitConstInitVal(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::ConstInitValContext* SillyParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 10, SillyParser::RuleConstInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SillyParser::ADD:
      case SillyParser::SUB:
      case SillyParser::LPAREN:
      case SillyParser::NOT:
      case SillyParser::INTEGER:
      case SillyParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(93);
        constExp();
        break;
      }

      case SillyParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(94);
        match(SillyParser::LBRACE);
        setState(99);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SillyParser::ADD)
          | (1ULL << SillyParser::SUB)
          | (1ULL << SillyParser::LPAREN)
          | (1ULL << SillyParser::LBRACE)
          | (1ULL << SillyParser::NOT)
          | (1ULL << SillyParser::INTEGER)
          | (1ULL << SillyParser::IDENTIFIER))) != 0)) {
          setState(95);
          constInitVal();

          setState(96);
          match(SillyParser::COMMA);
          setState(97);
          constInitVal();
        }
        setState(101);
        match(SillyParser::RBRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

SillyParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::BTypeContext* SillyParser::VarDeclContext::bType() {
  return getRuleContext<SillyParser::BTypeContext>(0);
}

std::vector<SillyParser::VarDefContext *> SillyParser::VarDeclContext::varDef() {
  return getRuleContexts<SillyParser::VarDefContext>();
}

SillyParser::VarDefContext* SillyParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<SillyParser::VarDefContext>(i);
}

tree::TerminalNode* SillyParser::VarDeclContext::SEM() {
  return getToken(SillyParser::SEM, 0);
}

tree::TerminalNode* SillyParser::VarDeclContext::COMMA() {
  return getToken(SillyParser::COMMA, 0);
}


size_t SillyParser::VarDeclContext::getRuleIndex() const {
  return SillyParser::RuleVarDecl;
}

void SillyParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void SillyParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


antlrcpp::Any SillyParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::VarDeclContext* SillyParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, SillyParser::RuleVarDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    bType();
    setState(105);
    varDef();

    setState(106);
    match(SillyParser::COMMA);
    setState(107);
    varDef();
    setState(109);
    match(SillyParser::SEM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

SillyParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::VarDefContext::IDENTIFIER() {
  return getToken(SillyParser::IDENTIFIER, 0);
}

std::vector<tree::TerminalNode *> SillyParser::VarDefContext::LBRACK() {
  return getTokens(SillyParser::LBRACK);
}

tree::TerminalNode* SillyParser::VarDefContext::LBRACK(size_t i) {
  return getToken(SillyParser::LBRACK, i);
}

std::vector<SillyParser::ConstExpContext *> SillyParser::VarDefContext::constExp() {
  return getRuleContexts<SillyParser::ConstExpContext>();
}

SillyParser::ConstExpContext* SillyParser::VarDefContext::constExp(size_t i) {
  return getRuleContext<SillyParser::ConstExpContext>(i);
}

std::vector<tree::TerminalNode *> SillyParser::VarDefContext::RBRACK() {
  return getTokens(SillyParser::RBRACK);
}

tree::TerminalNode* SillyParser::VarDefContext::RBRACK(size_t i) {
  return getToken(SillyParser::RBRACK, i);
}

tree::TerminalNode* SillyParser::VarDefContext::ASSIGN() {
  return getToken(SillyParser::ASSIGN, 0);
}

SillyParser::InitValContext* SillyParser::VarDefContext::initVal() {
  return getRuleContext<SillyParser::InitValContext>(0);
}


size_t SillyParser::VarDefContext::getRuleIndex() const {
  return SillyParser::RuleVarDef;
}

void SillyParser::VarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDef(this);
}

void SillyParser::VarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDef(this);
}


antlrcpp::Any SillyParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::VarDefContext* SillyParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, SillyParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(111);
      match(SillyParser::IDENTIFIER);
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SillyParser::LBRACK) {
        setState(112);
        match(SillyParser::LBRACK);
        setState(113);
        constExp();
        setState(114);
        match(SillyParser::RBRACK);
        setState(120);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(121);
      match(SillyParser::IDENTIFIER);
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SillyParser::LBRACK) {
        setState(122);
        match(SillyParser::LBRACK);
        setState(123);
        constExp();
        setState(124);
        match(SillyParser::RBRACK);
        setState(130);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(131);
      match(SillyParser::ASSIGN);
      setState(132);
      initVal();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitValContext ------------------------------------------------------------------

SillyParser::InitValContext::InitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::ExprContext* SillyParser::InitValContext::expr() {
  return getRuleContext<SillyParser::ExprContext>(0);
}

tree::TerminalNode* SillyParser::InitValContext::LBRACE() {
  return getToken(SillyParser::LBRACE, 0);
}

tree::TerminalNode* SillyParser::InitValContext::RBRACE() {
  return getToken(SillyParser::RBRACE, 0);
}

std::vector<SillyParser::InitValContext *> SillyParser::InitValContext::initVal() {
  return getRuleContexts<SillyParser::InitValContext>();
}

SillyParser::InitValContext* SillyParser::InitValContext::initVal(size_t i) {
  return getRuleContext<SillyParser::InitValContext>(i);
}

tree::TerminalNode* SillyParser::InitValContext::COMMA() {
  return getToken(SillyParser::COMMA, 0);
}


size_t SillyParser::InitValContext::getRuleIndex() const {
  return SillyParser::RuleInitVal;
}

void SillyParser::InitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitVal(this);
}

void SillyParser::InitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitVal(this);
}


antlrcpp::Any SillyParser::InitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitInitVal(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::InitValContext* SillyParser::initVal() {
  InitValContext *_localctx = _tracker.createInstance<InitValContext>(_ctx, getState());
  enterRule(_localctx, 16, SillyParser::RuleInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SillyParser::ADD:
      case SillyParser::SUB:
      case SillyParser::LPAREN:
      case SillyParser::NOT:
      case SillyParser::INTEGER:
      case SillyParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(135);
        expr();
        break;
      }

      case SillyParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(136);
        match(SillyParser::LBRACE);
        setState(141);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SillyParser::ADD)
          | (1ULL << SillyParser::SUB)
          | (1ULL << SillyParser::LPAREN)
          | (1ULL << SillyParser::LBRACE)
          | (1ULL << SillyParser::NOT)
          | (1ULL << SillyParser::INTEGER)
          | (1ULL << SillyParser::IDENTIFIER))) != 0)) {
          setState(137);
          initVal();

          setState(138);
          match(SillyParser::COMMA);
          setState(139);
          initVal();
        }
        setState(143);
        match(SillyParser::RBRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

SillyParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::FuncTypeContext* SillyParser::FuncDefContext::funcType() {
  return getRuleContext<SillyParser::FuncTypeContext>(0);
}

tree::TerminalNode* SillyParser::FuncDefContext::IDENTIFIER() {
  return getToken(SillyParser::IDENTIFIER, 0);
}

tree::TerminalNode* SillyParser::FuncDefContext::LPAREN() {
  return getToken(SillyParser::LPAREN, 0);
}

tree::TerminalNode* SillyParser::FuncDefContext::RPAREN() {
  return getToken(SillyParser::RPAREN, 0);
}

SillyParser::BlockContext* SillyParser::FuncDefContext::block() {
  return getRuleContext<SillyParser::BlockContext>(0);
}

SillyParser::FuncFParamsContext* SillyParser::FuncDefContext::funcFParams() {
  return getRuleContext<SillyParser::FuncFParamsContext>(0);
}


size_t SillyParser::FuncDefContext::getRuleIndex() const {
  return SillyParser::RuleFuncDef;
}

void SillyParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void SillyParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}


antlrcpp::Any SillyParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::FuncDefContext* SillyParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 18, SillyParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    funcType();
    setState(147);
    match(SillyParser::IDENTIFIER);
    setState(148);
    match(SillyParser::LPAREN);
    setState(150);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SillyParser::INT) {
      setState(149);
      funcFParams();
    }
    setState(152);
    match(SillyParser::RPAREN);
    setState(153);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

SillyParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::FuncTypeContext::VOID() {
  return getToken(SillyParser::VOID, 0);
}

tree::TerminalNode* SillyParser::FuncTypeContext::INT() {
  return getToken(SillyParser::INT, 0);
}


size_t SillyParser::FuncTypeContext::getRuleIndex() const {
  return SillyParser::RuleFuncType;
}

void SillyParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void SillyParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}


antlrcpp::Any SillyParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::FuncTypeContext* SillyParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, SillyParser::RuleFuncType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    _la = _input->LA(1);
    if (!(_la == SillyParser::INT

    || _la == SillyParser::VOID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

SillyParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SillyParser::FuncFParamContext *> SillyParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<SillyParser::FuncFParamContext>();
}

SillyParser::FuncFParamContext* SillyParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<SillyParser::FuncFParamContext>(i);
}

tree::TerminalNode* SillyParser::FuncFParamsContext::COMMA() {
  return getToken(SillyParser::COMMA, 0);
}


size_t SillyParser::FuncFParamsContext::getRuleIndex() const {
  return SillyParser::RuleFuncFParams;
}

void SillyParser::FuncFParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParams(this);
}

void SillyParser::FuncFParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParams(this);
}


antlrcpp::Any SillyParser::FuncFParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitFuncFParams(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::FuncFParamsContext* SillyParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 22, SillyParser::RuleFuncFParams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    funcFParam();

    setState(158);
    match(SillyParser::COMMA);
    setState(159);
    funcFParam();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

SillyParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::BTypeContext* SillyParser::FuncFParamContext::bType() {
  return getRuleContext<SillyParser::BTypeContext>(0);
}

tree::TerminalNode* SillyParser::FuncFParamContext::IDENTIFIER() {
  return getToken(SillyParser::IDENTIFIER, 0);
}

std::vector<tree::TerminalNode *> SillyParser::FuncFParamContext::LBRACK() {
  return getTokens(SillyParser::LBRACK);
}

tree::TerminalNode* SillyParser::FuncFParamContext::LBRACK(size_t i) {
  return getToken(SillyParser::LBRACK, i);
}

std::vector<tree::TerminalNode *> SillyParser::FuncFParamContext::RBRACK() {
  return getTokens(SillyParser::RBRACK);
}

tree::TerminalNode* SillyParser::FuncFParamContext::RBRACK(size_t i) {
  return getToken(SillyParser::RBRACK, i);
}

std::vector<SillyParser::ExprContext *> SillyParser::FuncFParamContext::expr() {
  return getRuleContexts<SillyParser::ExprContext>();
}

SillyParser::ExprContext* SillyParser::FuncFParamContext::expr(size_t i) {
  return getRuleContext<SillyParser::ExprContext>(i);
}


size_t SillyParser::FuncFParamContext::getRuleIndex() const {
  return SillyParser::RuleFuncFParam;
}

void SillyParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void SillyParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
}


antlrcpp::Any SillyParser::FuncFParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitFuncFParam(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::FuncFParamContext* SillyParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 24, SillyParser::RuleFuncFParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    bType();
    setState(162);
    match(SillyParser::IDENTIFIER);
    setState(174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SillyParser::LBRACK) {
      setState(163);
      match(SillyParser::LBRACK);
      setState(164);
      match(SillyParser::RBRACK);
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SillyParser::LBRACK) {
        setState(165);
        match(SillyParser::LBRACK);
        setState(166);
        expr();
        setState(167);
        match(SillyParser::RBRACK);
        setState(173);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

SillyParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::BlockContext::LBRACE() {
  return getToken(SillyParser::LBRACE, 0);
}

tree::TerminalNode* SillyParser::BlockContext::RBRACE() {
  return getToken(SillyParser::RBRACE, 0);
}

std::vector<SillyParser::BlockItemContext *> SillyParser::BlockContext::blockItem() {
  return getRuleContexts<SillyParser::BlockItemContext>();
}

SillyParser::BlockItemContext* SillyParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<SillyParser::BlockItemContext>(i);
}


size_t SillyParser::BlockContext::getRuleIndex() const {
  return SillyParser::RuleBlock;
}

void SillyParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void SillyParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any SillyParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::BlockContext* SillyParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 26, SillyParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(SillyParser::LBRACE);
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SillyParser::INT)
      | (1ULL << SillyParser::RETURN)
      | (1ULL << SillyParser::CONST)
      | (1ULL << SillyParser::IF)
      | (1ULL << SillyParser::WHILE)
      | (1ULL << SillyParser::BREAK)
      | (1ULL << SillyParser::CONTINUE)
      | (1ULL << SillyParser::ADD)
      | (1ULL << SillyParser::SUB)
      | (1ULL << SillyParser::LPAREN)
      | (1ULL << SillyParser::LBRACE)
      | (1ULL << SillyParser::NOT)
      | (1ULL << SillyParser::SEM)
      | (1ULL << SillyParser::INTEGER)
      | (1ULL << SillyParser::IDENTIFIER))) != 0)) {
      setState(177);
      blockItem();
      setState(182);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(183);
    match(SillyParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

SillyParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::DeclContext* SillyParser::BlockItemContext::decl() {
  return getRuleContext<SillyParser::DeclContext>(0);
}

SillyParser::StmtContext* SillyParser::BlockItemContext::stmt() {
  return getRuleContext<SillyParser::StmtContext>(0);
}


size_t SillyParser::BlockItemContext::getRuleIndex() const {
  return SillyParser::RuleBlockItem;
}

void SillyParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void SillyParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}


antlrcpp::Any SillyParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::BlockItemContext* SillyParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 28, SillyParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(187);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SillyParser::INT:
      case SillyParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(185);
        decl();
        break;
      }

      case SillyParser::RETURN:
      case SillyParser::IF:
      case SillyParser::WHILE:
      case SillyParser::BREAK:
      case SillyParser::CONTINUE:
      case SillyParser::ADD:
      case SillyParser::SUB:
      case SillyParser::LPAREN:
      case SillyParser::LBRACE:
      case SillyParser::NOT:
      case SillyParser::SEM:
      case SillyParser::INTEGER:
      case SillyParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(186);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

SillyParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::LValContext* SillyParser::StmtContext::lVal() {
  return getRuleContext<SillyParser::LValContext>(0);
}

tree::TerminalNode* SillyParser::StmtContext::ASSIGN() {
  return getToken(SillyParser::ASSIGN, 0);
}

SillyParser::ExprContext* SillyParser::StmtContext::expr() {
  return getRuleContext<SillyParser::ExprContext>(0);
}

tree::TerminalNode* SillyParser::StmtContext::SEM() {
  return getToken(SillyParser::SEM, 0);
}

SillyParser::BlockContext* SillyParser::StmtContext::block() {
  return getRuleContext<SillyParser::BlockContext>(0);
}

tree::TerminalNode* SillyParser::StmtContext::IF() {
  return getToken(SillyParser::IF, 0);
}

tree::TerminalNode* SillyParser::StmtContext::LPAREN() {
  return getToken(SillyParser::LPAREN, 0);
}

SillyParser::CondContext* SillyParser::StmtContext::cond() {
  return getRuleContext<SillyParser::CondContext>(0);
}

tree::TerminalNode* SillyParser::StmtContext::RPAREN() {
  return getToken(SillyParser::RPAREN, 0);
}

std::vector<SillyParser::StmtContext *> SillyParser::StmtContext::stmt() {
  return getRuleContexts<SillyParser::StmtContext>();
}

SillyParser::StmtContext* SillyParser::StmtContext::stmt(size_t i) {
  return getRuleContext<SillyParser::StmtContext>(i);
}

tree::TerminalNode* SillyParser::StmtContext::ELSE() {
  return getToken(SillyParser::ELSE, 0);
}

tree::TerminalNode* SillyParser::StmtContext::WHILE() {
  return getToken(SillyParser::WHILE, 0);
}

tree::TerminalNode* SillyParser::StmtContext::BREAK() {
  return getToken(SillyParser::BREAK, 0);
}

tree::TerminalNode* SillyParser::StmtContext::CONTINUE() {
  return getToken(SillyParser::CONTINUE, 0);
}

tree::TerminalNode* SillyParser::StmtContext::RETURN() {
  return getToken(SillyParser::RETURN, 0);
}


size_t SillyParser::StmtContext::getRuleIndex() const {
  return SillyParser::RuleStmt;
}

void SillyParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void SillyParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any SillyParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::StmtContext* SillyParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 30, SillyParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(189);
      lVal();
      setState(190);
      match(SillyParser::ASSIGN);
      setState(191);
      expr();
      setState(192);
      match(SillyParser::SEM);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(195);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SillyParser::ADD)
        | (1ULL << SillyParser::SUB)
        | (1ULL << SillyParser::LPAREN)
        | (1ULL << SillyParser::NOT)
        | (1ULL << SillyParser::INTEGER)
        | (1ULL << SillyParser::IDENTIFIER))) != 0)) {
        setState(194);
        expr();
      }
      setState(197);
      match(SillyParser::SEM);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(198);
      block();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(199);
      match(SillyParser::IF);
      setState(200);
      match(SillyParser::LPAREN);
      setState(201);
      cond();
      setState(202);
      match(SillyParser::RPAREN);
      setState(203);
      stmt();
      setState(206);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(204);
        match(SillyParser::ELSE);
        setState(205);
        stmt();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(208);
      match(SillyParser::WHILE);
      setState(209);
      match(SillyParser::LPAREN);
      setState(210);
      cond();
      setState(211);
      match(SillyParser::RPAREN);
      setState(212);
      stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(214);
      match(SillyParser::BREAK);
      setState(215);
      match(SillyParser::SEM);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(216);
      match(SillyParser::CONTINUE);
      setState(217);
      match(SillyParser::SEM);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(218);
      match(SillyParser::RETURN);
      setState(220);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SillyParser::ADD)
        | (1ULL << SillyParser::SUB)
        | (1ULL << SillyParser::LPAREN)
        | (1ULL << SillyParser::NOT)
        | (1ULL << SillyParser::INTEGER)
        | (1ULL << SillyParser::IDENTIFIER))) != 0)) {
        setState(219);
        expr();
      }
      setState(222);
      match(SillyParser::SEM);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

SillyParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::AddExpContext* SillyParser::ExprContext::addExp() {
  return getRuleContext<SillyParser::AddExpContext>(0);
}


size_t SillyParser::ExprContext::getRuleIndex() const {
  return SillyParser::RuleExpr;
}

void SillyParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void SillyParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any SillyParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::ExprContext* SillyParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 32, SillyParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    addExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

SillyParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::LOrExpContext* SillyParser::CondContext::lOrExp() {
  return getRuleContext<SillyParser::LOrExpContext>(0);
}


size_t SillyParser::CondContext::getRuleIndex() const {
  return SillyParser::RuleCond;
}

void SillyParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void SillyParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}


antlrcpp::Any SillyParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::CondContext* SillyParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 34, SillyParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

SillyParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::LValContext::IDENTIFIER() {
  return getToken(SillyParser::IDENTIFIER, 0);
}

std::vector<tree::TerminalNode *> SillyParser::LValContext::LBRACK() {
  return getTokens(SillyParser::LBRACK);
}

tree::TerminalNode* SillyParser::LValContext::LBRACK(size_t i) {
  return getToken(SillyParser::LBRACK, i);
}

std::vector<SillyParser::ExprContext *> SillyParser::LValContext::expr() {
  return getRuleContexts<SillyParser::ExprContext>();
}

SillyParser::ExprContext* SillyParser::LValContext::expr(size_t i) {
  return getRuleContext<SillyParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> SillyParser::LValContext::RBRACK() {
  return getTokens(SillyParser::RBRACK);
}

tree::TerminalNode* SillyParser::LValContext::RBRACK(size_t i) {
  return getToken(SillyParser::RBRACK, i);
}


size_t SillyParser::LValContext::getRuleIndex() const {
  return SillyParser::RuleLVal;
}

void SillyParser::LValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLVal(this);
}

void SillyParser::LValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLVal(this);
}


antlrcpp::Any SillyParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::LValContext* SillyParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 36, SillyParser::RuleLVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(SillyParser::IDENTIFIER);
    setState(236);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(230);
        match(SillyParser::LBRACK);
        setState(231);
        expr();
        setState(232);
        match(SillyParser::RBRACK); 
      }
      setState(238);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

SillyParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::PrimaryExpContext::LPAREN() {
  return getToken(SillyParser::LPAREN, 0);
}

SillyParser::ExprContext* SillyParser::PrimaryExpContext::expr() {
  return getRuleContext<SillyParser::ExprContext>(0);
}

tree::TerminalNode* SillyParser::PrimaryExpContext::RPAREN() {
  return getToken(SillyParser::RPAREN, 0);
}

SillyParser::LValContext* SillyParser::PrimaryExpContext::lVal() {
  return getRuleContext<SillyParser::LValContext>(0);
}

SillyParser::NumberContext* SillyParser::PrimaryExpContext::number() {
  return getRuleContext<SillyParser::NumberContext>(0);
}


size_t SillyParser::PrimaryExpContext::getRuleIndex() const {
  return SillyParser::RulePrimaryExp;
}

void SillyParser::PrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExp(this);
}

void SillyParser::PrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExp(this);
}


antlrcpp::Any SillyParser::PrimaryExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitPrimaryExp(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::PrimaryExpContext* SillyParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 38, SillyParser::RulePrimaryExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SillyParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(239);
        match(SillyParser::LPAREN);
        setState(240);
        expr();
        setState(241);
        match(SillyParser::RPAREN);
        break;
      }

      case SillyParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(243);
        lVal();
        break;
      }

      case SillyParser::INTEGER: {
        enterOuterAlt(_localctx, 3);
        setState(244);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

SillyParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::NumberContext::INTEGER() {
  return getToken(SillyParser::INTEGER, 0);
}


size_t SillyParser::NumberContext::getRuleIndex() const {
  return SillyParser::RuleNumber;
}

void SillyParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void SillyParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


antlrcpp::Any SillyParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::NumberContext* SillyParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 40, SillyParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(SillyParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

SillyParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::PrimaryExpContext* SillyParser::UnaryExpContext::primaryExp() {
  return getRuleContext<SillyParser::PrimaryExpContext>(0);
}

tree::TerminalNode* SillyParser::UnaryExpContext::IDENTIFIER() {
  return getToken(SillyParser::IDENTIFIER, 0);
}

tree::TerminalNode* SillyParser::UnaryExpContext::LPAREN() {
  return getToken(SillyParser::LPAREN, 0);
}

tree::TerminalNode* SillyParser::UnaryExpContext::RPAREN() {
  return getToken(SillyParser::RPAREN, 0);
}

SillyParser::FuncRParamsContext* SillyParser::UnaryExpContext::funcRParams() {
  return getRuleContext<SillyParser::FuncRParamsContext>(0);
}

SillyParser::UnaryOpContext* SillyParser::UnaryExpContext::unaryOp() {
  return getRuleContext<SillyParser::UnaryOpContext>(0);
}

SillyParser::UnaryExpContext* SillyParser::UnaryExpContext::unaryExp() {
  return getRuleContext<SillyParser::UnaryExpContext>(0);
}


size_t SillyParser::UnaryExpContext::getRuleIndex() const {
  return SillyParser::RuleUnaryExp;
}

void SillyParser::UnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExp(this);
}

void SillyParser::UnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExp(this);
}


antlrcpp::Any SillyParser::UnaryExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitUnaryExp(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::UnaryExpContext* SillyParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 42, SillyParser::RuleUnaryExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(259);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(249);
      primaryExp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(250);
      match(SillyParser::IDENTIFIER);
      setState(251);
      match(SillyParser::LPAREN);
      setState(253);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SillyParser::ADD)
        | (1ULL << SillyParser::SUB)
        | (1ULL << SillyParser::LPAREN)
        | (1ULL << SillyParser::NOT)
        | (1ULL << SillyParser::INTEGER)
        | (1ULL << SillyParser::IDENTIFIER))) != 0)) {
        setState(252);
        funcRParams();
      }
      setState(255);
      match(SillyParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(256);
      unaryOp();
      setState(257);
      unaryExp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

SillyParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::UnaryOpContext::ADD() {
  return getToken(SillyParser::ADD, 0);
}

tree::TerminalNode* SillyParser::UnaryOpContext::SUB() {
  return getToken(SillyParser::SUB, 0);
}

tree::TerminalNode* SillyParser::UnaryOpContext::NOT() {
  return getToken(SillyParser::NOT, 0);
}


size_t SillyParser::UnaryOpContext::getRuleIndex() const {
  return SillyParser::RuleUnaryOp;
}

void SillyParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void SillyParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}


antlrcpp::Any SillyParser::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::UnaryOpContext* SillyParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 44, SillyParser::RuleUnaryOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SillyParser::ADD)
      | (1ULL << SillyParser::SUB)
      | (1ULL << SillyParser::NOT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

SillyParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SillyParser::ExprContext *> SillyParser::FuncRParamsContext::expr() {
  return getRuleContexts<SillyParser::ExprContext>();
}

SillyParser::ExprContext* SillyParser::FuncRParamsContext::expr(size_t i) {
  return getRuleContext<SillyParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> SillyParser::FuncRParamsContext::COMMA() {
  return getTokens(SillyParser::COMMA);
}

tree::TerminalNode* SillyParser::FuncRParamsContext::COMMA(size_t i) {
  return getToken(SillyParser::COMMA, i);
}


size_t SillyParser::FuncRParamsContext::getRuleIndex() const {
  return SillyParser::RuleFuncRParams;
}

void SillyParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void SillyParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}


antlrcpp::Any SillyParser::FuncRParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitFuncRParams(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::FuncRParamsContext* SillyParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 46, SillyParser::RuleFuncRParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    expr();
    setState(268);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SillyParser::COMMA) {
      setState(264);
      match(SillyParser::COMMA);
      setState(265);
      expr();
      setState(270);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

SillyParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::UnaryExpContext* SillyParser::MulExpContext::unaryExp() {
  return getRuleContext<SillyParser::UnaryExpContext>(0);
}

SillyParser::MulExpContext* SillyParser::MulExpContext::mulExp() {
  return getRuleContext<SillyParser::MulExpContext>(0);
}

tree::TerminalNode* SillyParser::MulExpContext::MUL() {
  return getToken(SillyParser::MUL, 0);
}

tree::TerminalNode* SillyParser::MulExpContext::DIV() {
  return getToken(SillyParser::DIV, 0);
}

tree::TerminalNode* SillyParser::MulExpContext::MOD() {
  return getToken(SillyParser::MOD, 0);
}


size_t SillyParser::MulExpContext::getRuleIndex() const {
  return SillyParser::RuleMulExp;
}

void SillyParser::MulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExp(this);
}

void SillyParser::MulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExp(this);
}


antlrcpp::Any SillyParser::MulExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitMulExp(this);
  else
    return visitor->visitChildren(this);
}


SillyParser::MulExpContext* SillyParser::mulExp() {
   return mulExp(0);
}

SillyParser::MulExpContext* SillyParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SillyParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  SillyParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, SillyParser::RuleMulExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(272);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(279);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MulExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMulExp);
        setState(274);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(275);
        dynamic_cast<MulExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SillyParser::MUL)
          | (1ULL << SillyParser::DIV)
          | (1ULL << SillyParser::MOD))) != 0))) {
          dynamic_cast<MulExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(276);
        unaryExp(); 
      }
      setState(281);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

SillyParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::MulExpContext* SillyParser::AddExpContext::mulExp() {
  return getRuleContext<SillyParser::MulExpContext>(0);
}

SillyParser::AddExpContext* SillyParser::AddExpContext::addExp() {
  return getRuleContext<SillyParser::AddExpContext>(0);
}

tree::TerminalNode* SillyParser::AddExpContext::ADD() {
  return getToken(SillyParser::ADD, 0);
}

tree::TerminalNode* SillyParser::AddExpContext::SUB() {
  return getToken(SillyParser::SUB, 0);
}


size_t SillyParser::AddExpContext::getRuleIndex() const {
  return SillyParser::RuleAddExp;
}

void SillyParser::AddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExp(this);
}

void SillyParser::AddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExp(this);
}


antlrcpp::Any SillyParser::AddExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitAddExp(this);
  else
    return visitor->visitChildren(this);
}


SillyParser::AddExpContext* SillyParser::addExp() {
   return addExp(0);
}

SillyParser::AddExpContext* SillyParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SillyParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  SillyParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, SillyParser::RuleAddExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(283);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(290);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AddExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAddExp);
        setState(285);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(286);
        _la = _input->LA(1);
        if (!(_la == SillyParser::ADD

        || _la == SillyParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(287);
        mulExp(0); 
      }
      setState(292);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

SillyParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::AddExpContext* SillyParser::RelExpContext::addExp() {
  return getRuleContext<SillyParser::AddExpContext>(0);
}

SillyParser::RelExpContext* SillyParser::RelExpContext::relExp() {
  return getRuleContext<SillyParser::RelExpContext>(0);
}

tree::TerminalNode* SillyParser::RelExpContext::LT() {
  return getToken(SillyParser::LT, 0);
}

tree::TerminalNode* SillyParser::RelExpContext::GT() {
  return getToken(SillyParser::GT, 0);
}

tree::TerminalNode* SillyParser::RelExpContext::LE() {
  return getToken(SillyParser::LE, 0);
}

tree::TerminalNode* SillyParser::RelExpContext::GE() {
  return getToken(SillyParser::GE, 0);
}


size_t SillyParser::RelExpContext::getRuleIndex() const {
  return SillyParser::RuleRelExp;
}

void SillyParser::RelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExp(this);
}

void SillyParser::RelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExp(this);
}


antlrcpp::Any SillyParser::RelExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitRelExp(this);
  else
    return visitor->visitChildren(this);
}


SillyParser::RelExpContext* SillyParser::relExp() {
   return relExp(0);
}

SillyParser::RelExpContext* SillyParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SillyParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  SillyParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, SillyParser::RuleRelExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(294);
    addExp(0);
    _ctx->stop = _input->LT(-1);
    setState(301);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelExp);
        setState(296);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(297);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SillyParser::LT)
          | (1ULL << SillyParser::LE)
          | (1ULL << SillyParser::GT)
          | (1ULL << SillyParser::GE))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(298);
        addExp(0); 
      }
      setState(303);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

SillyParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::RelExpContext* SillyParser::EqExpContext::relExp() {
  return getRuleContext<SillyParser::RelExpContext>(0);
}

SillyParser::EqExpContext* SillyParser::EqExpContext::eqExp() {
  return getRuleContext<SillyParser::EqExpContext>(0);
}

tree::TerminalNode* SillyParser::EqExpContext::EQ() {
  return getToken(SillyParser::EQ, 0);
}

tree::TerminalNode* SillyParser::EqExpContext::NE() {
  return getToken(SillyParser::NE, 0);
}


size_t SillyParser::EqExpContext::getRuleIndex() const {
  return SillyParser::RuleEqExp;
}

void SillyParser::EqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExp(this);
}

void SillyParser::EqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExp(this);
}


antlrcpp::Any SillyParser::EqExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitEqExp(this);
  else
    return visitor->visitChildren(this);
}


SillyParser::EqExpContext* SillyParser::eqExp() {
   return eqExp(0);
}

SillyParser::EqExpContext* SillyParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SillyParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  SillyParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, SillyParser::RuleEqExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(305);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(312);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqExp);
        setState(307);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(308);
        _la = _input->LA(1);
        if (!(_la == SillyParser::EQ

        || _la == SillyParser::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(309);
        relExp(0); 
      }
      setState(314);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

SillyParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::EqExpContext* SillyParser::LAndExpContext::eqExp() {
  return getRuleContext<SillyParser::EqExpContext>(0);
}

SillyParser::LAndExpContext* SillyParser::LAndExpContext::lAndExp() {
  return getRuleContext<SillyParser::LAndExpContext>(0);
}

tree::TerminalNode* SillyParser::LAndExpContext::AND() {
  return getToken(SillyParser::AND, 0);
}


size_t SillyParser::LAndExpContext::getRuleIndex() const {
  return SillyParser::RuleLAndExp;
}

void SillyParser::LAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExp(this);
}

void SillyParser::LAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExp(this);
}


antlrcpp::Any SillyParser::LAndExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitLAndExp(this);
  else
    return visitor->visitChildren(this);
}


SillyParser::LAndExpContext* SillyParser::lAndExp() {
   return lAndExp(0);
}

SillyParser::LAndExpContext* SillyParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SillyParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  SillyParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, SillyParser::RuleLAndExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(316);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(323);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LAndExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLAndExp);
        setState(318);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(319);
        match(SillyParser::AND);
        setState(320);
        eqExp(0); 
      }
      setState(325);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

SillyParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::LAndExpContext* SillyParser::LOrExpContext::lAndExp() {
  return getRuleContext<SillyParser::LAndExpContext>(0);
}

SillyParser::LOrExpContext* SillyParser::LOrExpContext::lOrExp() {
  return getRuleContext<SillyParser::LOrExpContext>(0);
}

tree::TerminalNode* SillyParser::LOrExpContext::OR() {
  return getToken(SillyParser::OR, 0);
}


size_t SillyParser::LOrExpContext::getRuleIndex() const {
  return SillyParser::RuleLOrExp;
}

void SillyParser::LOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExp(this);
}

void SillyParser::LOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExp(this);
}


antlrcpp::Any SillyParser::LOrExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitLOrExp(this);
  else
    return visitor->visitChildren(this);
}


SillyParser::LOrExpContext* SillyParser::lOrExp() {
   return lOrExp(0);
}

SillyParser::LOrExpContext* SillyParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SillyParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  SillyParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, SillyParser::RuleLOrExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(327);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(334);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LOrExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLOrExp);
        setState(329);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(330);
        match(SillyParser::OR);
        setState(331);
        lAndExp(0); 
      }
      setState(336);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

SillyParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::AddExpContext* SillyParser::ConstExpContext::addExp() {
  return getRuleContext<SillyParser::AddExpContext>(0);
}


size_t SillyParser::ConstExpContext::getRuleIndex() const {
  return SillyParser::RuleConstExp;
}

void SillyParser::ConstExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExp(this);
}

void SillyParser::ConstExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExp(this);
}


antlrcpp::Any SillyParser::ConstExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitConstExp(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::ConstExpContext* SillyParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 60, SillyParser::RuleConstExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(337);
    addExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SillyParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 24: return mulExpSempred(dynamic_cast<MulExpContext *>(context), predicateIndex);
    case 25: return addExpSempred(dynamic_cast<AddExpContext *>(context), predicateIndex);
    case 26: return relExpSempred(dynamic_cast<RelExpContext *>(context), predicateIndex);
    case 27: return eqExpSempred(dynamic_cast<EqExpContext *>(context), predicateIndex);
    case 28: return lAndExpSempred(dynamic_cast<LAndExpContext *>(context), predicateIndex);
    case 29: return lOrExpSempred(dynamic_cast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SillyParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SillyParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SillyParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SillyParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SillyParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SillyParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SillyParser::_decisionToDFA;
atn::PredictionContextCache SillyParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SillyParser::_atn;
std::vector<uint16_t> SillyParser::_serializedATN;

std::vector<std::string> SillyParser::_ruleNames = {
  "compUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
  "varDecl", "varDef", "initVal", "funcDef", "funcType", "funcFParams", 
  "funcFParam", "block", "blockItem", "stmt", "expr", "cond", "lVal", "primaryExp", 
  "number", "unaryExp", "unaryOp", "funcRParams", "mulExp", "addExp", "relExp", 
  "eqExp", "lAndExp", "lOrExp", "constExp"
};

std::vector<std::string> SillyParser::_literalNames = {
  "", "'int'", "'void'", "'return'", "'const'", "'if'", "'else'", "'while'", 
  "'for'", "'break'", "'continue'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", 
  "')'", "'['", "']'", "'{'", "'}'", "'='", "'!'", "'<'", "'<='", "'>'", 
  "'>='", "'=='", "'!='", "'&&'", "'||'", "','", "';'"
};

std::vector<std::string> SillyParser::_symbolicNames = {
  "", "INT", "VOID", "RETURN", "CONST", "IF", "ELSE", "WHILE", "FOR", "BREAK", 
  "CONTINUE", "ADD", "SUB", "MUL", "DIV", "MOD", "LPAREN", "RPAREN", "LBRACK", 
  "RBRACK", "LBRACE", "RBRACE", "ASSIGN", "NOT", "LT", "LE", "GT", "GE", 
  "EQ", "NE", "AND", "OR", "COMMA", "SEM", "INTEGER", "IDENTIFIER", "STRING", 
  "WS", "INLINE_COMMENT"
};

dfa::Vocabulary SillyParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SillyParser::_tokenNames;

SillyParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x28, 0x156, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 
    0x43, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x46, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x4c, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x66, 0xa, 0x7, 0x3, 0x7, 0x5, 0x7, 0x69, 0xa, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x77, 0xa, 0x9, 
    0xc, 0x9, 0xe, 0x9, 0x7a, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x7, 0x9, 0x81, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x84, 0xb, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x88, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x90, 0xa, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0x93, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0x99, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xac, 
    0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xaf, 0xb, 0xe, 0x5, 0xe, 0xb1, 0xa, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xb5, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xb8, 
    0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xbe, 
    0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x5, 0x11, 0xc6, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0xd1, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x5, 0x11, 0xdf, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0xe2, 0xa, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xed, 0xa, 0x14, 0xc, 0x14, 0xe, 
    0x14, 0xf0, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x5, 0x15, 0xf8, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x100, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x106, 0xa, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x10d, 
    0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x110, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x118, 0xa, 0x1a, 
    0xc, 0x1a, 0xe, 0x1a, 0x11b, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x123, 0xa, 0x1b, 0xc, 0x1b, 
    0xe, 0x1b, 0x126, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x12e, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
    0x131, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x7, 0x1d, 0x139, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x13c, 
    0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x7, 0x1e, 0x144, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x147, 0xb, 
    0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x7, 0x1f, 0x14f, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x152, 0xb, 0x1f, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x2, 0x8, 0x32, 0x34, 0x36, 0x38, 0x3a, 
    0x3c, 0x21, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
    0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x2, 0x8, 0x3, 0x2, 
    0x3, 0x4, 0x4, 0x2, 0xd, 0xe, 0x19, 0x19, 0x3, 0x2, 0xf, 0x11, 0x3, 
    0x2, 0xd, 0xe, 0x3, 0x2, 0x1a, 0x1d, 0x3, 0x2, 0x1e, 0x1f, 0x2, 0x15c, 
    0x2, 0x44, 0x3, 0x2, 0x2, 0x2, 0x4, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x55, 0x3, 0x2, 0x2, 0x2, 0xa, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x68, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x87, 0x3, 0x2, 0x2, 0x2, 0x12, 0x92, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x16, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x18, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x20, 0xe1, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x24, 0xe5, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x28, 0xf7, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x105, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0x30, 0x109, 0x3, 0x2, 0x2, 0x2, 0x32, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x36, 0x127, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x132, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x13d, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x148, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x153, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x43, 0x5, 0x4, 0x3, 0x2, 0x41, 0x43, 0x5, 0x14, 0xb, 0x2, 
    0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0x47, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0x2, 0x2, 0x3, 0x48, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x4c, 0x5, 0x6, 0x4, 0x2, 0x4a, 0x4c, 0x5, 0xe, 0x8, 
    0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x6, 0x2, 0x2, 0x4e, 
    0x4f, 0x5, 0x8, 0x5, 0x2, 0x4f, 0x50, 0x5, 0xa, 0x6, 0x2, 0x50, 0x51, 
    0x7, 0x22, 0x2, 0x2, 0x51, 0x52, 0x5, 0xa, 0x6, 0x2, 0x52, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x23, 0x2, 0x2, 0x54, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x56, 0x7, 0x3, 0x2, 0x2, 0x56, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0x58, 0x7, 0x25, 0x2, 0x2, 0x58, 0x59, 0x7, 0x14, 0x2, 0x2, 
    0x59, 0x5a, 0x5, 0x3e, 0x20, 0x2, 0x5a, 0x5b, 0x7, 0x15, 0x2, 0x2, 0x5b, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x18, 0x2, 0x2, 0x5d, 0x5e, 
    0x5, 0xc, 0x7, 0x2, 0x5e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x69, 0x5, 
    0x3e, 0x20, 0x2, 0x60, 0x65, 0x7, 0x16, 0x2, 0x2, 0x61, 0x62, 0x5, 0xc, 
    0x7, 0x2, 0x62, 0x63, 0x7, 0x22, 0x2, 0x2, 0x63, 0x64, 0x5, 0xc, 0x7, 
    0x2, 0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 0x65, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x69, 0x7, 0x17, 0x2, 0x2, 0x68, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x68, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x5, 
    0x8, 0x5, 0x2, 0x6b, 0x6c, 0x5, 0x10, 0x9, 0x2, 0x6c, 0x6d, 0x7, 0x22, 
    0x2, 0x2, 0x6d, 0x6e, 0x5, 0x10, 0x9, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x6f, 0x70, 0x7, 0x23, 0x2, 0x2, 0x70, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x78, 0x7, 0x25, 0x2, 0x2, 0x72, 0x73, 0x7, 0x14, 0x2, 0x2, 0x73, 
    0x74, 0x5, 0x3e, 0x20, 0x2, 0x74, 0x75, 0x7, 0x15, 0x2, 0x2, 0x75, 0x77, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x72, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x79, 0x88, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x7b, 0x82, 0x7, 0x25, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x14, 0x2, 0x2, 
    0x7d, 0x7e, 0x5, 0x3e, 0x20, 0x2, 0x7e, 0x7f, 0x7, 0x15, 0x2, 0x2, 0x7f, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x81, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x83, 0x85, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x85, 0x86, 0x7, 0x18, 0x2, 0x2, 0x86, 0x88, 0x5, 0x12, 0xa, 
    0x2, 0x87, 0x71, 0x3, 0x2, 0x2, 0x2, 0x87, 0x7b, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x11, 0x3, 0x2, 0x2, 0x2, 0x89, 0x93, 0x5, 0x22, 0x12, 0x2, 0x8a, 
    0x8f, 0x7, 0x16, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0x12, 0xa, 0x2, 0x8c, 0x8d, 
    0x7, 0x22, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0x12, 0xa, 0x2, 0x8e, 0x90, 0x3, 
    0x2, 0x2, 0x2, 0x8f, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x93, 0x7, 0x17, 0x2, 
    0x2, 0x92, 0x89, 0x3, 0x2, 0x2, 0x2, 0x92, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x93, 0x13, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x5, 0x16, 0xc, 0x2, 0x95, 
    0x96, 0x7, 0x25, 0x2, 0x2, 0x96, 0x98, 0x7, 0x12, 0x2, 0x2, 0x97, 0x99, 
    0x5, 0x18, 0xd, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x13, 
    0x2, 0x2, 0x9b, 0x9c, 0x5, 0x1c, 0xf, 0x2, 0x9c, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0x9e, 0x9, 0x2, 0x2, 0x2, 0x9e, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0xa0, 0x5, 0x1a, 0xe, 0x2, 0xa0, 0xa1, 0x7, 0x22, 0x2, 0x2, 0xa1, 
    0xa2, 0x5, 0x1a, 0xe, 0x2, 0xa2, 0x19, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 
    0x5, 0x8, 0x5, 0x2, 0xa4, 0xb0, 0x7, 0x25, 0x2, 0x2, 0xa5, 0xa6, 0x7, 
    0x14, 0x2, 0x2, 0xa6, 0xad, 0x7, 0x15, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x14, 
    0x2, 0x2, 0xa8, 0xa9, 0x5, 0x22, 0x12, 0x2, 0xa9, 0xaa, 0x7, 0x15, 0x2, 
    0x2, 0xaa, 0xac, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0xb1, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb6, 0x7, 0x16, 
    0x2, 0x2, 0xb3, 0xb5, 0x5, 0x1e, 0x10, 0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 
    0x2, 0xb5, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x17, 0x2, 0x2, 0xba, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0xbe, 0x5, 0x4, 0x3, 0x2, 0xbc, 0xbe, 0x5, 
    0x20, 0x11, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbc, 0x3, 0x2, 
    0x2, 0x2, 0xbe, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x26, 0x14, 
    0x2, 0xc0, 0xc1, 0x7, 0x18, 0x2, 0x2, 0xc1, 0xc2, 0x5, 0x22, 0x12, 0x2, 
    0xc2, 0xc3, 0x7, 0x23, 0x2, 0x2, 0xc3, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xc4, 
    0xc6, 0x5, 0x22, 0x12, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xe2, 0x7, 
    0x23, 0x2, 0x2, 0xc8, 0xe2, 0x5, 0x1c, 0xf, 0x2, 0xc9, 0xca, 0x7, 0x7, 
    0x2, 0x2, 0xca, 0xcb, 0x7, 0x12, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x24, 0x13, 
    0x2, 0xcc, 0xcd, 0x7, 0x13, 0x2, 0x2, 0xcd, 0xd0, 0x5, 0x20, 0x11, 0x2, 
    0xce, 0xcf, 0x7, 0x8, 0x2, 0x2, 0xcf, 0xd1, 0x5, 0x20, 0x11, 0x2, 0xd0, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x9, 0x2, 0x2, 0xd3, 0xd4, 0x7, 
    0x12, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0x24, 0x13, 0x2, 0xd5, 0xd6, 0x7, 0x13, 
    0x2, 0x2, 0xd6, 0xd7, 0x5, 0x20, 0x11, 0x2, 0xd7, 0xe2, 0x3, 0x2, 0x2, 
    0x2, 0xd8, 0xd9, 0x7, 0xb, 0x2, 0x2, 0xd9, 0xe2, 0x7, 0x23, 0x2, 0x2, 
    0xda, 0xdb, 0x7, 0xc, 0x2, 0x2, 0xdb, 0xe2, 0x7, 0x23, 0x2, 0x2, 0xdc, 
    0xde, 0x7, 0x5, 0x2, 0x2, 0xdd, 0xdf, 0x5, 0x22, 0x12, 0x2, 0xde, 0xdd, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xe2, 0x7, 0x23, 0x2, 0x2, 0xe1, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0xe1, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xc8, 0x3, 0x2, 0x2, 
    0x2, 0xe1, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xd2, 0x3, 0x2, 0x2, 0x2, 
    0xe1, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0xe2, 0x21, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 
    0x5, 0x34, 0x1b, 0x2, 0xe4, 0x23, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x5, 
    0x3c, 0x1f, 0x2, 0xe6, 0x25, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xee, 0x7, 0x25, 
    0x2, 0x2, 0xe8, 0xe9, 0x7, 0x14, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x22, 0x12, 
    0x2, 0xea, 0xeb, 0x7, 0x15, 0x2, 0x2, 0xeb, 0xed, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xed, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xee, 
    0xec, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x3, 0x2, 0x2, 0x2, 0xef, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x7, 
    0x12, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x22, 0x12, 0x2, 0xf3, 0xf4, 0x7, 0x13, 
    0x2, 0x2, 0xf4, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf8, 0x5, 0x26, 0x14, 
    0x2, 0xf6, 0xf8, 0x5, 0x2a, 0x16, 0x2, 0xf7, 0xf1, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x24, 0x2, 0x2, 0xfa, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0xfb, 0x106, 0x5, 0x28, 0x15, 0x2, 0xfc, 0xfd, 0x7, 
    0x25, 0x2, 0x2, 0xfd, 0xff, 0x7, 0x12, 0x2, 0x2, 0xfe, 0x100, 0x5, 0x30, 
    0x19, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 
    0x2, 0x100, 0x101, 0x3, 0x2, 0x2, 0x2, 0x101, 0x106, 0x7, 0x13, 0x2, 
    0x2, 0x102, 0x103, 0x5, 0x2e, 0x18, 0x2, 0x103, 0x104, 0x5, 0x2c, 0x17, 
    0x2, 0x104, 0x106, 0x3, 0x2, 0x2, 0x2, 0x105, 0xfb, 0x3, 0x2, 0x2, 0x2, 
    0x105, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x105, 0x102, 0x3, 0x2, 0x2, 0x2, 0x106, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x9, 0x3, 0x2, 0x2, 0x108, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x109, 0x10e, 0x5, 0x22, 0x12, 0x2, 0x10a, 0x10b, 
    0x7, 0x22, 0x2, 0x2, 0x10b, 0x10d, 0x5, 0x22, 0x12, 0x2, 0x10c, 0x10a, 
    0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 
    0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x8, 
    0x1a, 0x1, 0x2, 0x112, 0x113, 0x5, 0x2c, 0x17, 0x2, 0x113, 0x119, 0x3, 
    0x2, 0x2, 0x2, 0x114, 0x115, 0xc, 0x3, 0x2, 0x2, 0x115, 0x116, 0x9, 
    0x4, 0x2, 0x2, 0x116, 0x118, 0x5, 0x2c, 0x17, 0x2, 0x117, 0x114, 0x3, 
    0x2, 0x2, 0x2, 0x118, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x119, 0x117, 0x3, 
    0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x8, 0x1b, 
    0x1, 0x2, 0x11d, 0x11e, 0x5, 0x32, 0x1a, 0x2, 0x11e, 0x124, 0x3, 0x2, 
    0x2, 0x2, 0x11f, 0x120, 0xc, 0x3, 0x2, 0x2, 0x120, 0x121, 0x9, 0x5, 
    0x2, 0x2, 0x121, 0x123, 0x5, 0x32, 0x1a, 0x2, 0x122, 0x11f, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x126, 0x3, 0x2, 0x2, 0x2, 0x124, 0x122, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x8, 0x1c, 0x1, 
    0x2, 0x128, 0x129, 0x5, 0x34, 0x1b, 0x2, 0x129, 0x12f, 0x3, 0x2, 0x2, 
    0x2, 0x12a, 0x12b, 0xc, 0x3, 0x2, 0x2, 0x12b, 0x12c, 0x9, 0x6, 0x2, 
    0x2, 0x12c, 0x12e, 0x5, 0x34, 0x1b, 0x2, 0x12d, 0x12a, 0x3, 0x2, 0x2, 
    0x2, 0x12e, 0x131, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x12f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x8, 0x1d, 0x1, 0x2, 
    0x133, 0x134, 0x5, 0x36, 0x1c, 0x2, 0x134, 0x13a, 0x3, 0x2, 0x2, 0x2, 
    0x135, 0x136, 0xc, 0x3, 0x2, 0x2, 0x136, 0x137, 0x9, 0x7, 0x2, 0x2, 
    0x137, 0x139, 0x5, 0x36, 0x1c, 0x2, 0x138, 0x135, 0x3, 0x2, 0x2, 0x2, 
    0x139, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x13c, 
    0x13a, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x8, 0x1e, 0x1, 0x2, 0x13e, 
    0x13f, 0x5, 0x38, 0x1d, 0x2, 0x13f, 0x145, 0x3, 0x2, 0x2, 0x2, 0x140, 
    0x141, 0xc, 0x3, 0x2, 0x2, 0x141, 0x142, 0x7, 0x20, 0x2, 0x2, 0x142, 
    0x144, 0x5, 0x38, 0x1d, 0x2, 0x143, 0x140, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x147, 0x3, 0x2, 0x2, 0x2, 0x145, 0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 
    0x146, 0x3, 0x2, 0x2, 0x2, 0x146, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x147, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x8, 0x1f, 0x1, 0x2, 0x149, 0x14a, 
    0x5, 0x3a, 0x1e, 0x2, 0x14a, 0x150, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 
    0xc, 0x3, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0x21, 0x2, 0x2, 0x14d, 0x14f, 
    0x5, 0x3a, 0x1e, 0x2, 0x14e, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x152, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 
    0x3, 0x2, 0x2, 0x2, 0x151, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x152, 0x150, 0x3, 
    0x2, 0x2, 0x2, 0x153, 0x154, 0x5, 0x34, 0x1b, 0x2, 0x154, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x20, 0x42, 0x44, 0x4b, 0x65, 0x68, 0x78, 0x82, 0x87, 
    0x8f, 0x92, 0x98, 0xad, 0xb0, 0xb6, 0xbd, 0xc5, 0xd0, 0xde, 0xe1, 0xee, 
    0xf7, 0xff, 0x105, 0x10e, 0x119, 0x124, 0x12f, 0x13a, 0x145, 0x150, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SillyParser::Initializer SillyParser::_init;
