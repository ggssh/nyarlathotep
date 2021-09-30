
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
    setState(36);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SillyParser::INT)
      | (1ULL << SillyParser::VOID)
      | (1ULL << SillyParser::CONST))) != 0)) {
      setState(34);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SillyParser::INT:
        case SillyParser::CONST: {
          setState(32);
          decl();
          break;
        }

        case SillyParser::VOID: {
          setState(33);
          funcDef();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(38);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(39);
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
    setState(43);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SillyParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(41);
        constDecl();
        break;
      }

      case SillyParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(42);
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

tree::TerminalNode* SillyParser::ConstDeclContext::INT() {
  return getToken(SillyParser::INT, 0);
}

std::vector<SillyParser::ConstDefContext *> SillyParser::ConstDeclContext::constDef() {
  return getRuleContexts<SillyParser::ConstDefContext>();
}

SillyParser::ConstDefContext* SillyParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<SillyParser::ConstDefContext>(i);
}

tree::TerminalNode* SillyParser::ConstDeclContext::SEMICOLON() {
  return getToken(SillyParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> SillyParser::ConstDeclContext::COMMA() {
  return getTokens(SillyParser::COMMA);
}

tree::TerminalNode* SillyParser::ConstDeclContext::COMMA(size_t i) {
  return getToken(SillyParser::COMMA, i);
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
    setState(45);
    match(SillyParser::CONST);
    setState(46);
    match(SillyParser::INT);
    setState(47);
    constDef();
    setState(52);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SillyParser::COMMA) {
      setState(48);
      match(SillyParser::COMMA);
      setState(49);
      constDef();
      setState(54);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(55);
    match(SillyParser::SEMICOLON);
   
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

std::vector<SillyParser::ExprContext *> SillyParser::ConstDefContext::expr() {
  return getRuleContexts<SillyParser::ExprContext>();
}

SillyParser::ExprContext* SillyParser::ConstDefContext::expr(size_t i) {
  return getRuleContext<SillyParser::ExprContext>(i);
}

tree::TerminalNode* SillyParser::ConstDefContext::LBRACK() {
  return getToken(SillyParser::LBRACK, 0);
}

tree::TerminalNode* SillyParser::ConstDefContext::RBRACK() {
  return getToken(SillyParser::RBRACK, 0);
}

tree::TerminalNode* SillyParser::ConstDefContext::LBRACE() {
  return getToken(SillyParser::LBRACE, 0);
}

tree::TerminalNode* SillyParser::ConstDefContext::RBRACE() {
  return getToken(SillyParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> SillyParser::ConstDefContext::COMMA() {
  return getTokens(SillyParser::COMMA);
}

tree::TerminalNode* SillyParser::ConstDefContext::COMMA(size_t i) {
  return getToken(SillyParser::COMMA, i);
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
  enterRule(_localctx, 6, SillyParser::RuleConstDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(78);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(57);
      match(SillyParser::IDENTIFIER);
      setState(58);
      match(SillyParser::ASSIGN);
      setState(59);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(60);
      match(SillyParser::IDENTIFIER);
      setState(61);
      match(SillyParser::LBRACK);
      setState(63);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SillyParser::ADD)
        | (1ULL << SillyParser::SUB)
        | (1ULL << SillyParser::LPAREN)
        | (1ULL << SillyParser::NUMBER))) != 0)) {
        setState(62);
        expr(0);
      }
      setState(65);
      match(SillyParser::RBRACK);
      setState(66);
      match(SillyParser::ASSIGN);
      setState(67);
      match(SillyParser::LBRACE);
      setState(68);
      expr(0);
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SillyParser::COMMA) {
        setState(69);
        match(SillyParser::COMMA);
        setState(70);
        expr(0);
        setState(75);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(76);
      match(SillyParser::RBRACE);
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

//----------------- VarDeclContext ------------------------------------------------------------------

SillyParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::VarDeclContext::INT() {
  return getToken(SillyParser::INT, 0);
}

std::vector<SillyParser::VarDefContext *> SillyParser::VarDeclContext::varDef() {
  return getRuleContexts<SillyParser::VarDefContext>();
}

SillyParser::VarDefContext* SillyParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<SillyParser::VarDefContext>(i);
}

tree::TerminalNode* SillyParser::VarDeclContext::SEMICOLON() {
  return getToken(SillyParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> SillyParser::VarDeclContext::COMMA() {
  return getTokens(SillyParser::COMMA);
}

tree::TerminalNode* SillyParser::VarDeclContext::COMMA(size_t i) {
  return getToken(SillyParser::COMMA, i);
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
  enterRule(_localctx, 8, SillyParser::RuleVarDecl);
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
    setState(80);
    match(SillyParser::INT);
    setState(81);
    varDef();
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SillyParser::COMMA) {
      setState(82);
      match(SillyParser::COMMA);
      setState(83);
      varDef();
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(89);
    match(SillyParser::SEMICOLON);
   
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

tree::TerminalNode* SillyParser::VarDefContext::LBRACK() {
  return getToken(SillyParser::LBRACK, 0);
}

std::vector<SillyParser::ExprContext *> SillyParser::VarDefContext::expr() {
  return getRuleContexts<SillyParser::ExprContext>();
}

SillyParser::ExprContext* SillyParser::VarDefContext::expr(size_t i) {
  return getRuleContext<SillyParser::ExprContext>(i);
}

tree::TerminalNode* SillyParser::VarDefContext::RBRACK() {
  return getToken(SillyParser::RBRACK, 0);
}

tree::TerminalNode* SillyParser::VarDefContext::ASSIGN() {
  return getToken(SillyParser::ASSIGN, 0);
}

tree::TerminalNode* SillyParser::VarDefContext::LBRACE() {
  return getToken(SillyParser::LBRACE, 0);
}

tree::TerminalNode* SillyParser::VarDefContext::RBRACE() {
  return getToken(SillyParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> SillyParser::VarDefContext::COMMA() {
  return getTokens(SillyParser::COMMA);
}

tree::TerminalNode* SillyParser::VarDefContext::COMMA(size_t i) {
  return getToken(SillyParser::COMMA, i);
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
  enterRule(_localctx, 10, SillyParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(118);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(91);
      match(SillyParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(92);
      match(SillyParser::IDENTIFIER);
      setState(93);
      match(SillyParser::LBRACK);
      setState(94);
      expr(0);
      setState(95);
      match(SillyParser::RBRACK);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(97);
      match(SillyParser::IDENTIFIER);
      setState(98);
      match(SillyParser::ASSIGN);
      setState(99);
      expr(0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(100);
      match(SillyParser::IDENTIFIER);
      setState(101);
      match(SillyParser::LBRACK);
      setState(103);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SillyParser::ADD)
        | (1ULL << SillyParser::SUB)
        | (1ULL << SillyParser::LPAREN)
        | (1ULL << SillyParser::NUMBER))) != 0)) {
        setState(102);
        expr(0);
      }
      setState(105);
      match(SillyParser::RBRACK);
      setState(106);
      match(SillyParser::ASSIGN);
      setState(107);
      match(SillyParser::LBRACE);
      setState(108);
      expr(0);
      setState(113);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SillyParser::COMMA) {
        setState(109);
        match(SillyParser::COMMA);
        setState(110);
        expr(0);
        setState(115);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(116);
      match(SillyParser::RBRACE);
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

//----------------- FuncDefContext ------------------------------------------------------------------

SillyParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::FuncDefContext::VOID() {
  return getToken(SillyParser::VOID, 0);
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
  enterRule(_localctx, 12, SillyParser::RuleFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(SillyParser::VOID);
    setState(121);
    match(SillyParser::IDENTIFIER);
    setState(122);
    match(SillyParser::LPAREN);
    setState(123);
    match(SillyParser::RPAREN);
    setState(124);
    block();
   
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
  enterRule(_localctx, 14, SillyParser::RuleBlock);
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
    setState(126);
    match(SillyParser::LBRACE);
    setState(130);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SillyParser::INT)
      | (1ULL << SillyParser::CONST)
      | (1ULL << SillyParser::IF)
      | (1ULL << SillyParser::WHILE)
      | (1ULL << SillyParser::LBRACE)
      | (1ULL << SillyParser::SEMICOLON)
      | (1ULL << SillyParser::IDENTIFIER))) != 0)) {
      setState(127);
      blockItem();
      setState(132);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(133);
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
  enterRule(_localctx, 16, SillyParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(137);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SillyParser::INT:
      case SillyParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(135);
        decl();
        break;
      }

      case SillyParser::IF:
      case SillyParser::WHILE:
      case SillyParser::LBRACE:
      case SillyParser::SEMICOLON:
      case SillyParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(136);
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

tree::TerminalNode* SillyParser::StmtContext::SEMICOLON() {
  return getToken(SillyParser::SEMICOLON, 0);
}

tree::TerminalNode* SillyParser::StmtContext::IDENTIFIER() {
  return getToken(SillyParser::IDENTIFIER, 0);
}

tree::TerminalNode* SillyParser::StmtContext::LPAREN() {
  return getToken(SillyParser::LPAREN, 0);
}

tree::TerminalNode* SillyParser::StmtContext::RPAREN() {
  return getToken(SillyParser::RPAREN, 0);
}

SillyParser::BlockContext* SillyParser::StmtContext::block() {
  return getRuleContext<SillyParser::BlockContext>(0);
}

tree::TerminalNode* SillyParser::StmtContext::IF() {
  return getToken(SillyParser::IF, 0);
}

SillyParser::CondContext* SillyParser::StmtContext::cond() {
  return getRuleContext<SillyParser::CondContext>(0);
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
  enterRule(_localctx, 18, SillyParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(139);
      lVal();
      setState(140);
      match(SillyParser::ASSIGN);
      setState(141);
      expr(0);
      setState(142);
      match(SillyParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(144);
      match(SillyParser::IDENTIFIER);
      setState(145);
      match(SillyParser::LPAREN);
      setState(146);
      match(SillyParser::RPAREN);
      setState(147);
      match(SillyParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(148);
      block();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(149);
      match(SillyParser::IF);
      setState(150);
      match(SillyParser::LPAREN);
      setState(151);
      cond();
      setState(152);
      match(SillyParser::RPAREN);
      setState(153);
      stmt();
      setState(156);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
      case 1: {
        setState(154);
        match(SillyParser::ELSE);
        setState(155);
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
      setState(158);
      match(SillyParser::WHILE);
      setState(159);
      match(SillyParser::LPAREN);
      setState(160);
      cond();
      setState(161);
      match(SillyParser::RPAREN);
      setState(162);
      stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(164);
      match(SillyParser::SEMICOLON);
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

//----------------- LValContext ------------------------------------------------------------------

SillyParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::LValContext::IDENTIFIER() {
  return getToken(SillyParser::IDENTIFIER, 0);
}

tree::TerminalNode* SillyParser::LValContext::LBRACK() {
  return getToken(SillyParser::LBRACK, 0);
}

SillyParser::ExprContext* SillyParser::LValContext::expr() {
  return getRuleContext<SillyParser::ExprContext>(0);
}

tree::TerminalNode* SillyParser::LValContext::RBRACK() {
  return getToken(SillyParser::RBRACK, 0);
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
  enterRule(_localctx, 20, SillyParser::RuleLVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(173);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(167);
      match(SillyParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(168);
      match(SillyParser::IDENTIFIER);
      setState(169);
      match(SillyParser::LBRACK);
      setState(170);
      expr(0);
      setState(171);
      match(SillyParser::RBRACK);
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

//----------------- CondContext ------------------------------------------------------------------

SillyParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SillyParser::ExprContext *> SillyParser::CondContext::expr() {
  return getRuleContexts<SillyParser::ExprContext>();
}

SillyParser::ExprContext* SillyParser::CondContext::expr(size_t i) {
  return getRuleContext<SillyParser::ExprContext>(i);
}

SillyParser::RelOpContext* SillyParser::CondContext::relOp() {
  return getRuleContext<SillyParser::RelOpContext>(0);
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
  enterRule(_localctx, 22, SillyParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    expr(0);
    setState(176);
    relOp();
    setState(177);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

SillyParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::RelOpContext::EQ() {
  return getToken(SillyParser::EQ, 0);
}

tree::TerminalNode* SillyParser::RelOpContext::NE() {
  return getToken(SillyParser::NE, 0);
}

tree::TerminalNode* SillyParser::RelOpContext::LT() {
  return getToken(SillyParser::LT, 0);
}

tree::TerminalNode* SillyParser::RelOpContext::GT() {
  return getToken(SillyParser::GT, 0);
}

tree::TerminalNode* SillyParser::RelOpContext::LE() {
  return getToken(SillyParser::LE, 0);
}

tree::TerminalNode* SillyParser::RelOpContext::GE() {
  return getToken(SillyParser::GE, 0);
}


size_t SillyParser::RelOpContext::getRuleIndex() const {
  return SillyParser::RuleRelOp;
}

void SillyParser::RelOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelOp(this);
}

void SillyParser::RelOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelOp(this);
}


antlrcpp::Any SillyParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::RelOpContext* SillyParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 24, SillyParser::RuleRelOp);
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
    setState(179);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SillyParser::LT)
      | (1ULL << SillyParser::LE)
      | (1ULL << SillyParser::GT)
      | (1ULL << SillyParser::GE)
      | (1ULL << SillyParser::EQ)
      | (1ULL << SillyParser::NE))) != 0))) {
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

//----------------- ExprContext ------------------------------------------------------------------

SillyParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SillyParser::UnaryOpContext* SillyParser::ExprContext::unaryOp() {
  return getRuleContext<SillyParser::UnaryOpContext>(0);
}

std::vector<SillyParser::ExprContext *> SillyParser::ExprContext::expr() {
  return getRuleContexts<SillyParser::ExprContext>();
}

SillyParser::ExprContext* SillyParser::ExprContext::expr(size_t i) {
  return getRuleContext<SillyParser::ExprContext>(i);
}

tree::TerminalNode* SillyParser::ExprContext::LPAREN() {
  return getToken(SillyParser::LPAREN, 0);
}

tree::TerminalNode* SillyParser::ExprContext::RPAREN() {
  return getToken(SillyParser::RPAREN, 0);
}

tree::TerminalNode* SillyParser::ExprContext::NUMBER() {
  return getToken(SillyParser::NUMBER, 0);
}

SillyParser::BinOpContext* SillyParser::ExprContext::binOp() {
  return getRuleContext<SillyParser::BinOpContext>(0);
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
   return expr(0);
}

SillyParser::ExprContext* SillyParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SillyParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  SillyParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, SillyParser::RuleExpr, precedence);

    

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
    setState(190);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SillyParser::ADD:
      case SillyParser::SUB: {
        setState(182);
        unaryOp();
        setState(183);
        expr(3);
        break;
      }

      case SillyParser::LPAREN: {
        setState(185);
        match(SillyParser::LPAREN);
        setState(186);
        expr(0);
        setState(187);
        match(SillyParser::RPAREN);
        break;
      }

      case SillyParser::NUMBER: {
        setState(189);
        match(SillyParser::NUMBER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(198);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(192);

        if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
        setState(193);
        binOp();
        setState(194);
        expr(5); 
      }
      setState(200);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BinOpContext ------------------------------------------------------------------

SillyParser::BinOpContext::BinOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::BinOpContext::ADD() {
  return getToken(SillyParser::ADD, 0);
}

tree::TerminalNode* SillyParser::BinOpContext::SUB() {
  return getToken(SillyParser::SUB, 0);
}

tree::TerminalNode* SillyParser::BinOpContext::MUL() {
  return getToken(SillyParser::MUL, 0);
}

tree::TerminalNode* SillyParser::BinOpContext::DIV() {
  return getToken(SillyParser::DIV, 0);
}

tree::TerminalNode* SillyParser::BinOpContext::MOD() {
  return getToken(SillyParser::MOD, 0);
}


size_t SillyParser::BinOpContext::getRuleIndex() const {
  return SillyParser::RuleBinOp;
}

void SillyParser::BinOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinOp(this);
}

void SillyParser::BinOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinOp(this);
}


antlrcpp::Any SillyParser::BinOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitBinOp(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::BinOpContext* SillyParser::binOp() {
  BinOpContext *_localctx = _tracker.createInstance<BinOpContext>(_ctx, getState());
  enterRule(_localctx, 28, SillyParser::RuleBinOp);
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
    setState(201);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SillyParser::ADD)
      | (1ULL << SillyParser::SUB)
      | (1ULL << SillyParser::MUL)
      | (1ULL << SillyParser::DIV)
      | (1ULL << SillyParser::MOD))) != 0))) {
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
  enterRule(_localctx, 30, SillyParser::RuleUnaryOp);
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
    setState(203);
    _la = _input->LA(1);
    if (!(_la == SillyParser::ADD

    || _la == SillyParser::SUB)) {
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

bool SillyParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 13: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SillyParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);

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
  "compUnit", "decl", "constDecl", "constDef", "varDecl", "varDef", "funcDef", 
  "block", "blockItem", "stmt", "lVal", "cond", "relOp", "expr", "binOp", 
  "unaryOp"
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
  "EQ", "NE", "AND", "OR", "COMMA", "SEMICOLON", "NUMBER", "IDENTIFIER", 
  "STRING", "WHITESPACE", "INLINE_COMMENT"
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
    0x3, 0x28, 0xd0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x3, 0x2, 
    0x3, 0x2, 0x7, 0x2, 0x25, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x28, 0xb, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2e, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x35, 0xa, 0x4, 
    0xc, 0x4, 0xe, 0x4, 0x38, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x42, 0xa, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x4a, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x4d, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x51, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0x57, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x5a, 0xb, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x6a, 
    0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0x72, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x75, 0xb, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x79, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x83, 0xa, 0x9, 
    0xc, 0x9, 0xe, 0x9, 0x86, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0x8c, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x9f, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0xa8, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xb0, 0xa, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0xc1, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 
    0xc7, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xca, 0xb, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x2, 0x3, 0x1c, 0x12, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x2, 0x5, 0x3, 0x2, 0x1a, 0x1f, 0x3, 0x2, 0xd, 0x11, 0x3, 0x2, 
    0xd, 0xe, 0x2, 0xd8, 0x2, 0x26, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x52, 0x3, 0x2, 0x2, 0x2, 0xc, 0x78, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x80, 0x3, 0x2, 0x2, 0x2, 0x12, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x16, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xb5, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xcb, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x22, 0x25, 0x5, 0x4, 0x3, 0x2, 
    0x23, 0x25, 0x5, 0xe, 0x8, 0x2, 0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 0x28, 0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 0x2, 0x27, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x2, 
    0x2, 0x3, 0x2a, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2e, 0x5, 0x6, 0x4, 
    0x2, 0x2c, 0x2e, 0x5, 0xa, 0x6, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2f, 
    0x30, 0x7, 0x6, 0x2, 0x2, 0x30, 0x31, 0x7, 0x3, 0x2, 0x2, 0x31, 0x36, 
    0x5, 0x8, 0x5, 0x2, 0x32, 0x33, 0x7, 0x22, 0x2, 0x2, 0x33, 0x35, 0x5, 
    0x8, 0x5, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x35, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x37, 0x39, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x3a, 0x7, 0x23, 0x2, 0x2, 0x3a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3b, 
    0x3c, 0x7, 0x25, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x18, 0x2, 0x2, 0x3d, 0x51, 
    0x5, 0x1c, 0xf, 0x2, 0x3e, 0x3f, 0x7, 0x25, 0x2, 0x2, 0x3f, 0x41, 0x7, 
    0x14, 0x2, 0x2, 0x40, 0x42, 0x5, 0x1c, 0xf, 0x2, 0x41, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x43, 0x44, 0x7, 0x15, 0x2, 0x2, 0x44, 0x45, 0x7, 0x18, 0x2, 0x2, 
    0x45, 0x46, 0x7, 0x16, 0x2, 0x2, 0x46, 0x4b, 0x5, 0x1c, 0xf, 0x2, 0x47, 
    0x48, 0x7, 0x22, 0x2, 0x2, 0x48, 0x4a, 0x5, 0x1c, 0xf, 0x2, 0x49, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x17, 0x2, 
    0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x50, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x51, 0x9, 0x3, 0x2, 0x2, 0x2, 0x52, 
    0x53, 0x7, 0x3, 0x2, 0x2, 0x53, 0x58, 0x5, 0xc, 0x7, 0x2, 0x54, 0x55, 
    0x7, 0x22, 0x2, 0x2, 0x55, 0x57, 0x5, 0xc, 0x7, 0x2, 0x56, 0x54, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x23, 0x2, 0x2, 
    0x5c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x79, 0x7, 0x25, 0x2, 0x2, 0x5e, 
    0x5f, 0x7, 0x25, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x14, 0x2, 0x2, 0x60, 0x61, 
    0x5, 0x1c, 0xf, 0x2, 0x61, 0x62, 0x7, 0x15, 0x2, 0x2, 0x62, 0x79, 0x3, 
    0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x25, 0x2, 0x2, 0x64, 0x65, 0x7, 0x18, 
    0x2, 0x2, 0x65, 0x79, 0x5, 0x1c, 0xf, 0x2, 0x66, 0x67, 0x7, 0x25, 0x2, 
    0x2, 0x67, 0x69, 0x7, 0x14, 0x2, 0x2, 0x68, 0x6a, 0x5, 0x1c, 0xf, 0x2, 
    0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x15, 0x2, 0x2, 0x6c, 0x6d, 
    0x7, 0x18, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x16, 0x2, 0x2, 0x6e, 0x73, 0x5, 
    0x1c, 0xf, 0x2, 0x6f, 0x70, 0x7, 0x22, 0x2, 0x2, 0x70, 0x72, 0x5, 0x1c, 
    0xf, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x72, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x76, 0x3, 0x2, 0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x77, 0x7, 0x17, 0x2, 0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 0x78, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x78, 0x63, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x66, 0x3, 0x2, 0x2, 0x2, 0x79, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x7, 0x4, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x25, 0x2, 
    0x2, 0x7c, 0x7d, 0x7, 0x12, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x13, 0x2, 0x2, 
    0x7e, 0x7f, 0x5, 0x10, 0x9, 0x2, 0x7f, 0xf, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x84, 0x7, 0x16, 0x2, 0x2, 0x81, 0x83, 0x5, 0x12, 0xa, 0x2, 0x82, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x83, 0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 0x17, 0x2, 
    0x2, 0x88, 0x11, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8c, 0x5, 0x4, 0x3, 0x2, 
    0x8a, 0x8c, 0x5, 0x14, 0xb, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 
    0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 
    0x5, 0x16, 0xc, 0x2, 0x8e, 0x8f, 0x7, 0x18, 0x2, 0x2, 0x8f, 0x90, 0x5, 
    0x1c, 0xf, 0x2, 0x90, 0x91, 0x7, 0x23, 0x2, 0x2, 0x91, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x93, 0x7, 0x25, 0x2, 0x2, 0x93, 0x94, 0x7, 0x12, 0x2, 
    0x2, 0x94, 0x95, 0x7, 0x13, 0x2, 0x2, 0x95, 0xa8, 0x7, 0x23, 0x2, 0x2, 
    0x96, 0xa8, 0x5, 0x10, 0x9, 0x2, 0x97, 0x98, 0x7, 0x7, 0x2, 0x2, 0x98, 
    0x99, 0x7, 0x12, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x18, 0xd, 0x2, 0x9a, 0x9b, 
    0x7, 0x13, 0x2, 0x2, 0x9b, 0x9e, 0x5, 0x14, 0xb, 0x2, 0x9c, 0x9d, 0x7, 
    0x8, 0x2, 0x2, 0x9d, 0x9f, 0x5, 0x14, 0xb, 0x2, 0x9e, 0x9c, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0xa1, 0x7, 0x9, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x12, 0x2, 0x2, 
    0xa2, 0xa3, 0x5, 0x18, 0xd, 0x2, 0xa3, 0xa4, 0x7, 0x13, 0x2, 0x2, 0xa4, 
    0xa5, 0x5, 0x14, 0xb, 0x2, 0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 
    0x7, 0x23, 0x2, 0x2, 0xa7, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0x96, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0xa7, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa6, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xb0, 0x7, 0x25, 0x2, 0x2, 
    0xaa, 0xab, 0x7, 0x25, 0x2, 0x2, 0xab, 0xac, 0x7, 0x14, 0x2, 0x2, 0xac, 
    0xad, 0x5, 0x1c, 0xf, 0x2, 0xad, 0xae, 0x7, 0x15, 0x2, 0x2, 0xae, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0xaf, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xaa, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x1c, 
    0xf, 0x2, 0xb2, 0xb3, 0x5, 0x1a, 0xe, 0x2, 0xb3, 0xb4, 0x5, 0x1c, 0xf, 
    0x2, 0xb4, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x9, 0x2, 0x2, 0x2, 
    0xb6, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x8, 0xf, 0x1, 0x2, 0xb8, 
    0xb9, 0x5, 0x20, 0x11, 0x2, 0xb9, 0xba, 0x5, 0x1c, 0xf, 0x5, 0xba, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x12, 0x2, 0x2, 0xbc, 0xbd, 0x5, 
    0x1c, 0xf, 0x2, 0xbd, 0xbe, 0x7, 0x13, 0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xc1, 0x7, 0x24, 0x2, 0x2, 0xc0, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbf, 0x3, 0x2, 0x2, 0x2, 
    0xc1, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0xc, 0x6, 0x2, 0x2, 0xc3, 
    0xc4, 0x5, 0x1e, 0x10, 0x2, 0xc4, 0xc5, 0x5, 0x1c, 0xf, 0x7, 0xc5, 0xc7, 
    0x3, 0x2, 0x2, 0x2, 0xc6, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0xcc, 0x9, 0x3, 0x2, 0x2, 0xcc, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0xcd, 0xce, 0x9, 0x4, 0x2, 0x2, 0xce, 0x21, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x24, 0x26, 0x2d, 0x36, 0x41, 0x4b, 0x50, 0x58, 0x69, 0x73, 0x78, 0x84, 
    0x8b, 0x9e, 0xa7, 0xaf, 0xc0, 0xc8, 
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
