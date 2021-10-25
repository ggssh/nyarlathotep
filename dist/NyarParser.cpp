
// Generated from Nyar.g4 by ANTLR 4.9


#include "NyarListener.h"
#include "NyarVisitor.h"

#include "NyarParser.h"


using namespace antlrcpp;
using namespace antlr4;

NyarParser::NyarParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

NyarParser::~NyarParser() {
  delete _interpreter;
}

std::string NyarParser::getGrammarFileName() const {
  return "Nyar.g4";
}

const std::vector<std::string>& NyarParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& NyarParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

NyarParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::CompUnitContext::EOF() {
  return getToken(NyarParser::EOF, 0);
}

std::vector<NyarParser::DeclContext *> NyarParser::CompUnitContext::decl() {
  return getRuleContexts<NyarParser::DeclContext>();
}

NyarParser::DeclContext* NyarParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<NyarParser::DeclContext>(i);
}

std::vector<NyarParser::FuncDefContext *> NyarParser::CompUnitContext::funcDef() {
  return getRuleContexts<NyarParser::FuncDefContext>();
}

NyarParser::FuncDefContext* NyarParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<NyarParser::FuncDefContext>(i);
}


size_t NyarParser::CompUnitContext::getRuleIndex() const {
  return NyarParser::RuleCompUnit;
}

void NyarParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void NyarParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}


antlrcpp::Any NyarParser::CompUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitCompUnit(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::CompUnitContext* NyarParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, NyarParser::RuleCompUnit);
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
    setState(34);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << NyarParser::INT)
      | (1ULL << NyarParser::VOID)
      | (1ULL << NyarParser::CONST))) != 0)) {
      setState(32);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case NyarParser::INT:
        case NyarParser::CONST: {
          setState(30);
          decl();
          break;
        }

        case NyarParser::VOID: {
          setState(31);
          funcDef();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(36);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(37);
    match(NyarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

NyarParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NyarParser::ConstDeclContext* NyarParser::DeclContext::constDecl() {
  return getRuleContext<NyarParser::ConstDeclContext>(0);
}

NyarParser::VarDeclContext* NyarParser::DeclContext::varDecl() {
  return getRuleContext<NyarParser::VarDeclContext>(0);
}


size_t NyarParser::DeclContext::getRuleIndex() const {
  return NyarParser::RuleDecl;
}

void NyarParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void NyarParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


antlrcpp::Any NyarParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::DeclContext* NyarParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, NyarParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(41);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case NyarParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(39);
        constDecl();
        break;
      }

      case NyarParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(40);
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

NyarParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::ConstDeclContext::CONST() {
  return getToken(NyarParser::CONST, 0);
}

tree::TerminalNode* NyarParser::ConstDeclContext::INT() {
  return getToken(NyarParser::INT, 0);
}

std::vector<NyarParser::ConstDefContext *> NyarParser::ConstDeclContext::constDef() {
  return getRuleContexts<NyarParser::ConstDefContext>();
}

NyarParser::ConstDefContext* NyarParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<NyarParser::ConstDefContext>(i);
}

tree::TerminalNode* NyarParser::ConstDeclContext::SEMICOLON() {
  return getToken(NyarParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> NyarParser::ConstDeclContext::COMMA() {
  return getTokens(NyarParser::COMMA);
}

tree::TerminalNode* NyarParser::ConstDeclContext::COMMA(size_t i) {
  return getToken(NyarParser::COMMA, i);
}


size_t NyarParser::ConstDeclContext::getRuleIndex() const {
  return NyarParser::RuleConstDecl;
}

void NyarParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void NyarParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}


antlrcpp::Any NyarParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::ConstDeclContext* NyarParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, NyarParser::RuleConstDecl);
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
    setState(43);
    match(NyarParser::CONST);
    setState(44);
    match(NyarParser::INT);
    setState(45);
    constDef();
    setState(50);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == NyarParser::COMMA) {
      setState(46);
      match(NyarParser::COMMA);
      setState(47);
      constDef();
      setState(52);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(53);
    match(NyarParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

NyarParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::ConstDefContext::IDENTIFIER() {
  return getToken(NyarParser::IDENTIFIER, 0);
}

tree::TerminalNode* NyarParser::ConstDefContext::ASSIGN() {
  return getToken(NyarParser::ASSIGN, 0);
}

std::vector<NyarParser::ExprContext *> NyarParser::ConstDefContext::expr() {
  return getRuleContexts<NyarParser::ExprContext>();
}

NyarParser::ExprContext* NyarParser::ConstDefContext::expr(size_t i) {
  return getRuleContext<NyarParser::ExprContext>(i);
}

tree::TerminalNode* NyarParser::ConstDefContext::LBRACK() {
  return getToken(NyarParser::LBRACK, 0);
}

tree::TerminalNode* NyarParser::ConstDefContext::RBRACK() {
  return getToken(NyarParser::RBRACK, 0);
}

tree::TerminalNode* NyarParser::ConstDefContext::LBRACE() {
  return getToken(NyarParser::LBRACE, 0);
}

tree::TerminalNode* NyarParser::ConstDefContext::RBRACE() {
  return getToken(NyarParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> NyarParser::ConstDefContext::COMMA() {
  return getTokens(NyarParser::COMMA);
}

tree::TerminalNode* NyarParser::ConstDefContext::COMMA(size_t i) {
  return getToken(NyarParser::COMMA, i);
}


size_t NyarParser::ConstDefContext::getRuleIndex() const {
  return NyarParser::RuleConstDef;
}

void NyarParser::ConstDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDef(this);
}

void NyarParser::ConstDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDef(this);
}


antlrcpp::Any NyarParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::ConstDefContext* NyarParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 6, NyarParser::RuleConstDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(55);
      match(NyarParser::IDENTIFIER);
      setState(56);
      match(NyarParser::ASSIGN);
      setState(57);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(58);
      match(NyarParser::IDENTIFIER);
      setState(59);
      match(NyarParser::LBRACK);
      setState(61);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << NyarParser::ADD)
        | (1ULL << NyarParser::SUB)
        | (1ULL << NyarParser::LPAREN)
        | (1ULL << NyarParser::NUMBER)
        | (1ULL << NyarParser::IDENTIFIER))) != 0)) {
        setState(60);
        expr(0);
      }
      setState(63);
      match(NyarParser::RBRACK);
      setState(64);
      match(NyarParser::ASSIGN);
      setState(65);
      match(NyarParser::LBRACE);
      setState(66);
      expr(0);
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == NyarParser::COMMA) {
        setState(67);
        match(NyarParser::COMMA);
        setState(68);
        expr(0);
        setState(73);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(74);
      match(NyarParser::RBRACE);
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

NyarParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::VarDeclContext::INT() {
  return getToken(NyarParser::INT, 0);
}

std::vector<NyarParser::VarDefContext *> NyarParser::VarDeclContext::varDef() {
  return getRuleContexts<NyarParser::VarDefContext>();
}

NyarParser::VarDefContext* NyarParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<NyarParser::VarDefContext>(i);
}

tree::TerminalNode* NyarParser::VarDeclContext::SEMICOLON() {
  return getToken(NyarParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> NyarParser::VarDeclContext::COMMA() {
  return getTokens(NyarParser::COMMA);
}

tree::TerminalNode* NyarParser::VarDeclContext::COMMA(size_t i) {
  return getToken(NyarParser::COMMA, i);
}


size_t NyarParser::VarDeclContext::getRuleIndex() const {
  return NyarParser::RuleVarDecl;
}

void NyarParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void NyarParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


antlrcpp::Any NyarParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::VarDeclContext* NyarParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, NyarParser::RuleVarDecl);
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
    setState(78);
    match(NyarParser::INT);
    setState(79);
    varDef();
    setState(84);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == NyarParser::COMMA) {
      setState(80);
      match(NyarParser::COMMA);
      setState(81);
      varDef();
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(87);
    match(NyarParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

NyarParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::VarDefContext::IDENTIFIER() {
  return getToken(NyarParser::IDENTIFIER, 0);
}

tree::TerminalNode* NyarParser::VarDefContext::LBRACK() {
  return getToken(NyarParser::LBRACK, 0);
}

std::vector<NyarParser::ExprContext *> NyarParser::VarDefContext::expr() {
  return getRuleContexts<NyarParser::ExprContext>();
}

NyarParser::ExprContext* NyarParser::VarDefContext::expr(size_t i) {
  return getRuleContext<NyarParser::ExprContext>(i);
}

tree::TerminalNode* NyarParser::VarDefContext::RBRACK() {
  return getToken(NyarParser::RBRACK, 0);
}

tree::TerminalNode* NyarParser::VarDefContext::ASSIGN() {
  return getToken(NyarParser::ASSIGN, 0);
}

tree::TerminalNode* NyarParser::VarDefContext::LBRACE() {
  return getToken(NyarParser::LBRACE, 0);
}

tree::TerminalNode* NyarParser::VarDefContext::RBRACE() {
  return getToken(NyarParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> NyarParser::VarDefContext::COMMA() {
  return getTokens(NyarParser::COMMA);
}

tree::TerminalNode* NyarParser::VarDefContext::COMMA(size_t i) {
  return getToken(NyarParser::COMMA, i);
}


size_t NyarParser::VarDefContext::getRuleIndex() const {
  return NyarParser::RuleVarDef;
}

void NyarParser::VarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDef(this);
}

void NyarParser::VarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDef(this);
}


antlrcpp::Any NyarParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::VarDefContext* NyarParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 10, NyarParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(116);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(89);
      match(NyarParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(90);
      match(NyarParser::IDENTIFIER);
      setState(91);
      match(NyarParser::LBRACK);
      setState(92);
      expr(0);
      setState(93);
      match(NyarParser::RBRACK);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(95);
      match(NyarParser::IDENTIFIER);
      setState(96);
      match(NyarParser::ASSIGN);
      setState(97);
      expr(0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(98);
      match(NyarParser::IDENTIFIER);
      setState(99);
      match(NyarParser::LBRACK);
      setState(101);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << NyarParser::ADD)
        | (1ULL << NyarParser::SUB)
        | (1ULL << NyarParser::LPAREN)
        | (1ULL << NyarParser::NUMBER)
        | (1ULL << NyarParser::IDENTIFIER))) != 0)) {
        setState(100);
        expr(0);
      }
      setState(103);
      match(NyarParser::RBRACK);
      setState(104);
      match(NyarParser::ASSIGN);
      setState(105);
      match(NyarParser::LBRACE);
      setState(106);
      expr(0);
      setState(111);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == NyarParser::COMMA) {
        setState(107);
        match(NyarParser::COMMA);
        setState(108);
        expr(0);
        setState(113);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(114);
      match(NyarParser::RBRACE);
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

NyarParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::FuncDefContext::VOID() {
  return getToken(NyarParser::VOID, 0);
}

tree::TerminalNode* NyarParser::FuncDefContext::IDENTIFIER() {
  return getToken(NyarParser::IDENTIFIER, 0);
}

tree::TerminalNode* NyarParser::FuncDefContext::LPAREN() {
  return getToken(NyarParser::LPAREN, 0);
}

tree::TerminalNode* NyarParser::FuncDefContext::RPAREN() {
  return getToken(NyarParser::RPAREN, 0);
}

NyarParser::BlockContext* NyarParser::FuncDefContext::block() {
  return getRuleContext<NyarParser::BlockContext>(0);
}


size_t NyarParser::FuncDefContext::getRuleIndex() const {
  return NyarParser::RuleFuncDef;
}

void NyarParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void NyarParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}


antlrcpp::Any NyarParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::FuncDefContext* NyarParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 12, NyarParser::RuleFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(NyarParser::VOID);
    setState(119);
    match(NyarParser::IDENTIFIER);
    setState(120);
    match(NyarParser::LPAREN);
    setState(121);
    match(NyarParser::RPAREN);
    setState(122);
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

NyarParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::BlockContext::LBRACE() {
  return getToken(NyarParser::LBRACE, 0);
}

tree::TerminalNode* NyarParser::BlockContext::RBRACE() {
  return getToken(NyarParser::RBRACE, 0);
}

std::vector<NyarParser::DeclContext *> NyarParser::BlockContext::decl() {
  return getRuleContexts<NyarParser::DeclContext>();
}

NyarParser::DeclContext* NyarParser::BlockContext::decl(size_t i) {
  return getRuleContext<NyarParser::DeclContext>(i);
}

std::vector<NyarParser::StmtContext *> NyarParser::BlockContext::stmt() {
  return getRuleContexts<NyarParser::StmtContext>();
}

NyarParser::StmtContext* NyarParser::BlockContext::stmt(size_t i) {
  return getRuleContext<NyarParser::StmtContext>(i);
}


size_t NyarParser::BlockContext::getRuleIndex() const {
  return NyarParser::RuleBlock;
}

void NyarParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void NyarParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any NyarParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::BlockContext* NyarParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 14, NyarParser::RuleBlock);
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
    setState(124);
    match(NyarParser::LBRACE);
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << NyarParser::INT)
      | (1ULL << NyarParser::CONST)
      | (1ULL << NyarParser::IF)
      | (1ULL << NyarParser::WHILE)
      | (1ULL << NyarParser::LBRACE)
      | (1ULL << NyarParser::SEMICOLON)
      | (1ULL << NyarParser::IDENTIFIER))) != 0)) {
      setState(127);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case NyarParser::INT:
        case NyarParser::CONST: {
          setState(125);
          decl();
          break;
        }

        case NyarParser::IF:
        case NyarParser::WHILE:
        case NyarParser::LBRACE:
        case NyarParser::SEMICOLON:
        case NyarParser::IDENTIFIER: {
          setState(126);
          stmt();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(131);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(132);
    match(NyarParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

NyarParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NyarParser::LValContext* NyarParser::StmtContext::lVal() {
  return getRuleContext<NyarParser::LValContext>(0);
}

tree::TerminalNode* NyarParser::StmtContext::ASSIGN() {
  return getToken(NyarParser::ASSIGN, 0);
}

NyarParser::ExprContext* NyarParser::StmtContext::expr() {
  return getRuleContext<NyarParser::ExprContext>(0);
}

tree::TerminalNode* NyarParser::StmtContext::SEMICOLON() {
  return getToken(NyarParser::SEMICOLON, 0);
}

tree::TerminalNode* NyarParser::StmtContext::IDENTIFIER() {
  return getToken(NyarParser::IDENTIFIER, 0);
}

tree::TerminalNode* NyarParser::StmtContext::LPAREN() {
  return getToken(NyarParser::LPAREN, 0);
}

tree::TerminalNode* NyarParser::StmtContext::RPAREN() {
  return getToken(NyarParser::RPAREN, 0);
}

NyarParser::BlockContext* NyarParser::StmtContext::block() {
  return getRuleContext<NyarParser::BlockContext>(0);
}

tree::TerminalNode* NyarParser::StmtContext::IF() {
  return getToken(NyarParser::IF, 0);
}

NyarParser::CondContext* NyarParser::StmtContext::cond() {
  return getRuleContext<NyarParser::CondContext>(0);
}

std::vector<NyarParser::StmtContext *> NyarParser::StmtContext::stmt() {
  return getRuleContexts<NyarParser::StmtContext>();
}

NyarParser::StmtContext* NyarParser::StmtContext::stmt(size_t i) {
  return getRuleContext<NyarParser::StmtContext>(i);
}

tree::TerminalNode* NyarParser::StmtContext::ELSE() {
  return getToken(NyarParser::ELSE, 0);
}

tree::TerminalNode* NyarParser::StmtContext::WHILE() {
  return getToken(NyarParser::WHILE, 0);
}


size_t NyarParser::StmtContext::getRuleIndex() const {
  return NyarParser::RuleStmt;
}

void NyarParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void NyarParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any NyarParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::StmtContext* NyarParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 16, NyarParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(134);
      lVal();
      setState(135);
      match(NyarParser::ASSIGN);
      setState(136);
      expr(0);
      setState(137);
      match(NyarParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(139);
      match(NyarParser::IDENTIFIER);
      setState(140);
      match(NyarParser::LPAREN);
      setState(141);
      match(NyarParser::RPAREN);
      setState(142);
      match(NyarParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(143);
      block();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(144);
      match(NyarParser::IF);
      setState(145);
      match(NyarParser::LPAREN);
      setState(146);
      cond();
      setState(147);
      match(NyarParser::RPAREN);
      setState(148);
      stmt();
      setState(151);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
      case 1: {
        setState(149);
        match(NyarParser::ELSE);
        setState(150);
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
      setState(153);
      match(NyarParser::WHILE);
      setState(154);
      match(NyarParser::LPAREN);
      setState(155);
      cond();
      setState(156);
      match(NyarParser::RPAREN);
      setState(157);
      stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(159);
      match(NyarParser::SEMICOLON);
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

NyarParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::LValContext::IDENTIFIER() {
  return getToken(NyarParser::IDENTIFIER, 0);
}

tree::TerminalNode* NyarParser::LValContext::LBRACK() {
  return getToken(NyarParser::LBRACK, 0);
}

NyarParser::ExprContext* NyarParser::LValContext::expr() {
  return getRuleContext<NyarParser::ExprContext>(0);
}

tree::TerminalNode* NyarParser::LValContext::RBRACK() {
  return getToken(NyarParser::RBRACK, 0);
}


size_t NyarParser::LValContext::getRuleIndex() const {
  return NyarParser::RuleLVal;
}

void NyarParser::LValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLVal(this);
}

void NyarParser::LValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLVal(this);
}


antlrcpp::Any NyarParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::LValContext* NyarParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 18, NyarParser::RuleLVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(162);
      match(NyarParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(163);
      match(NyarParser::IDENTIFIER);
      setState(164);
      match(NyarParser::LBRACK);
      setState(165);
      expr(0);
      setState(166);
      match(NyarParser::RBRACK);
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

NyarParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NyarParser::ExprContext *> NyarParser::CondContext::expr() {
  return getRuleContexts<NyarParser::ExprContext>();
}

NyarParser::ExprContext* NyarParser::CondContext::expr(size_t i) {
  return getRuleContext<NyarParser::ExprContext>(i);
}

NyarParser::RelOpContext* NyarParser::CondContext::relOp() {
  return getRuleContext<NyarParser::RelOpContext>(0);
}


size_t NyarParser::CondContext::getRuleIndex() const {
  return NyarParser::RuleCond;
}

void NyarParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void NyarParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}


antlrcpp::Any NyarParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::CondContext* NyarParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 20, NyarParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    expr(0);
    setState(171);
    relOp();
    setState(172);
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

NyarParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::RelOpContext::EQ() {
  return getToken(NyarParser::EQ, 0);
}

tree::TerminalNode* NyarParser::RelOpContext::NE() {
  return getToken(NyarParser::NE, 0);
}

tree::TerminalNode* NyarParser::RelOpContext::LT() {
  return getToken(NyarParser::LT, 0);
}

tree::TerminalNode* NyarParser::RelOpContext::GT() {
  return getToken(NyarParser::GT, 0);
}

tree::TerminalNode* NyarParser::RelOpContext::LE() {
  return getToken(NyarParser::LE, 0);
}

tree::TerminalNode* NyarParser::RelOpContext::GE() {
  return getToken(NyarParser::GE, 0);
}


size_t NyarParser::RelOpContext::getRuleIndex() const {
  return NyarParser::RuleRelOp;
}

void NyarParser::RelOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelOp(this);
}

void NyarParser::RelOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelOp(this);
}


antlrcpp::Any NyarParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::RelOpContext* NyarParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 22, NyarParser::RuleRelOp);
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
    setState(174);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << NyarParser::LT)
      | (1ULL << NyarParser::LE)
      | (1ULL << NyarParser::GT)
      | (1ULL << NyarParser::GE)
      | (1ULL << NyarParser::EQ)
      | (1ULL << NyarParser::NE))) != 0))) {
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

NyarParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NyarParser::UnaryOpContext* NyarParser::ExprContext::unaryOp() {
  return getRuleContext<NyarParser::UnaryOpContext>(0);
}

std::vector<NyarParser::ExprContext *> NyarParser::ExprContext::expr() {
  return getRuleContexts<NyarParser::ExprContext>();
}

NyarParser::ExprContext* NyarParser::ExprContext::expr(size_t i) {
  return getRuleContext<NyarParser::ExprContext>(i);
}

tree::TerminalNode* NyarParser::ExprContext::LPAREN() {
  return getToken(NyarParser::LPAREN, 0);
}

tree::TerminalNode* NyarParser::ExprContext::RPAREN() {
  return getToken(NyarParser::RPAREN, 0);
}

NyarParser::LValContext* NyarParser::ExprContext::lVal() {
  return getRuleContext<NyarParser::LValContext>(0);
}

tree::TerminalNode* NyarParser::ExprContext::NUMBER() {
  return getToken(NyarParser::NUMBER, 0);
}

NyarParser::BinOpContext* NyarParser::ExprContext::binOp() {
  return getRuleContext<NyarParser::BinOpContext>(0);
}


size_t NyarParser::ExprContext::getRuleIndex() const {
  return NyarParser::RuleExpr;
}

void NyarParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void NyarParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any NyarParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


NyarParser::ExprContext* NyarParser::expr() {
   return expr(0);
}

NyarParser::ExprContext* NyarParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  NyarParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  NyarParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, NyarParser::RuleExpr, precedence);

    

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
    setState(186);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case NyarParser::ADD:
      case NyarParser::SUB: {
        setState(177);
        unaryOp();
        setState(178);
        expr(4);
        break;
      }

      case NyarParser::LPAREN: {
        setState(180);
        match(NyarParser::LPAREN);
        setState(181);
        expr(0);
        setState(182);
        match(NyarParser::RPAREN);
        break;
      }

      case NyarParser::IDENTIFIER: {
        setState(184);
        lVal();
        break;
      }

      case NyarParser::NUMBER: {
        setState(185);
        match(NyarParser::NUMBER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(194);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(188);

        if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
        setState(189);
        binOp();
        setState(190);
        expr(6); 
      }
      setState(196);
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

NyarParser::BinOpContext::BinOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::BinOpContext::ADD() {
  return getToken(NyarParser::ADD, 0);
}

tree::TerminalNode* NyarParser::BinOpContext::SUB() {
  return getToken(NyarParser::SUB, 0);
}

tree::TerminalNode* NyarParser::BinOpContext::MUL() {
  return getToken(NyarParser::MUL, 0);
}

tree::TerminalNode* NyarParser::BinOpContext::DIV() {
  return getToken(NyarParser::DIV, 0);
}

tree::TerminalNode* NyarParser::BinOpContext::MOD() {
  return getToken(NyarParser::MOD, 0);
}


size_t NyarParser::BinOpContext::getRuleIndex() const {
  return NyarParser::RuleBinOp;
}

void NyarParser::BinOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinOp(this);
}

void NyarParser::BinOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinOp(this);
}


antlrcpp::Any NyarParser::BinOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitBinOp(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::BinOpContext* NyarParser::binOp() {
  BinOpContext *_localctx = _tracker.createInstance<BinOpContext>(_ctx, getState());
  enterRule(_localctx, 26, NyarParser::RuleBinOp);
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
    setState(197);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << NyarParser::ADD)
      | (1ULL << NyarParser::SUB)
      | (1ULL << NyarParser::MUL)
      | (1ULL << NyarParser::DIV)
      | (1ULL << NyarParser::MOD))) != 0))) {
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

NyarParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NyarParser::UnaryOpContext::ADD() {
  return getToken(NyarParser::ADD, 0);
}

tree::TerminalNode* NyarParser::UnaryOpContext::SUB() {
  return getToken(NyarParser::SUB, 0);
}


size_t NyarParser::UnaryOpContext::getRuleIndex() const {
  return NyarParser::RuleUnaryOp;
}

void NyarParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void NyarParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NyarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}


antlrcpp::Any NyarParser::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NyarVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

NyarParser::UnaryOpContext* NyarParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 28, NyarParser::RuleUnaryOp);
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
    setState(199);
    _la = _input->LA(1);
    if (!(_la == NyarParser::ADD

    || _la == NyarParser::SUB)) {
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

bool NyarParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool NyarParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> NyarParser::_decisionToDFA;
atn::PredictionContextCache NyarParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN NyarParser::_atn;
std::vector<uint16_t> NyarParser::_serializedATN;

std::vector<std::string> NyarParser::_ruleNames = {
  "compUnit", "decl", "constDecl", "constDef", "varDecl", "varDef", "funcDef", 
  "block", "stmt", "lVal", "cond", "relOp", "expr", "binOp", "unaryOp"
};

std::vector<std::string> NyarParser::_literalNames = {
  "", "'int'", "'void'", "'return'", "'const'", "'if'", "'else'", "'while'", 
  "'for'", "'break'", "'continue'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", 
  "')'", "'['", "']'", "'{'", "'}'", "'='", "'!'", "'<'", "'<='", "'>'", 
  "'>='", "'=='", "'!='", "'&&'", "'||'", "','", "';'"
};

std::vector<std::string> NyarParser::_symbolicNames = {
  "", "INT", "VOID", "RETURN", "CONST", "IF", "ELSE", "WHILE", "FOR", "BREAK", 
  "CONTINUE", "ADD", "SUB", "MUL", "DIV", "MOD", "LPAREN", "RPAREN", "LBRACK", 
  "RBRACK", "LBRACE", "RBRACE", "ASSIGN", "NOT", "LT", "LE", "GT", "GE", 
  "EQ", "NE", "AND", "OR", "COMMA", "SEMICOLON", "NUMBER", "IDENTIFIER", 
  "STRING", "WHITESPACE", "INLINE_COMMENT", "BLOCK_COMMENT"
};

dfa::Vocabulary NyarParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> NyarParser::_tokenNames;

NyarParser::Initializer::Initializer() {
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
    0x3, 0x29, 0xcc, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x23, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x26, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x2c, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x33, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x36, 
    0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x40, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x48, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x4b, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x4f, 0xa, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x55, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x58, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x68, 0xa, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x70, 0xa, 0x7, 
    0xc, 0x7, 0xe, 0x7, 0x73, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x77, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x82, 0xa, 0x9, 0xc, 0x9, 0xe, 
    0x9, 0x85, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0x9a, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xa3, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xab, 0xa, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x5, 0xe, 0xbd, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x7, 0xe, 0xc3, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xc6, 0xb, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x2, 0x3, 0x1a, 
    0x11, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x2, 0x5, 0x3, 0x2, 0x1a, 0x1f, 0x3, 0x2, 0xd, 0x11, 
    0x3, 0x2, 0xd, 0xe, 0x2, 0xd6, 0x2, 0x24, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x50, 0x3, 0x2, 0x2, 0x2, 0xc, 0x76, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x78, 0x3, 0x2, 0x2, 0x2, 0x10, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0x14, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x16, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0xb0, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xbc, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc9, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0x23, 0x5, 0x4, 0x3, 0x2, 0x21, 0x23, 0x5, 0xe, 0x8, 
    0x2, 0x22, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x23, 0x26, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x27, 0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x7, 0x2, 0x2, 0x3, 0x28, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x2c, 0x5, 0x6, 0x4, 0x2, 0x2a, 0x2c, 0x5, 0xa, 
    0x6, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x6, 0x2, 0x2, 
    0x2e, 0x2f, 0x7, 0x3, 0x2, 0x2, 0x2f, 0x34, 0x5, 0x8, 0x5, 0x2, 0x30, 
    0x31, 0x7, 0x22, 0x2, 0x2, 0x31, 0x33, 0x5, 0x8, 0x5, 0x2, 0x32, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x33, 0x36, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x23, 0x2, 
    0x2, 0x38, 0x7, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x25, 0x2, 0x2, 
    0x3a, 0x3b, 0x7, 0x18, 0x2, 0x2, 0x3b, 0x4f, 0x5, 0x1a, 0xe, 0x2, 0x3c, 
    0x3d, 0x7, 0x25, 0x2, 0x2, 0x3d, 0x3f, 0x7, 0x14, 0x2, 0x2, 0x3e, 0x40, 
    0x5, 0x1a, 0xe, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x15, 
    0x2, 0x2, 0x42, 0x43, 0x7, 0x18, 0x2, 0x2, 0x43, 0x44, 0x7, 0x16, 0x2, 
    0x2, 0x44, 0x49, 0x5, 0x1a, 0xe, 0x2, 0x45, 0x46, 0x7, 0x22, 0x2, 0x2, 
    0x46, 0x48, 0x5, 0x1a, 0xe, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x17, 0x2, 0x2, 0x4d, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x39, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x4f, 0x9, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x7, 0x3, 0x2, 0x2, 
    0x51, 0x56, 0x5, 0xc, 0x7, 0x2, 0x52, 0x53, 0x7, 0x22, 0x2, 0x2, 0x53, 
    0x55, 0x5, 0xc, 0x7, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x55, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x59, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x59, 0x5a, 0x7, 0x23, 0x2, 0x2, 0x5a, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x77, 0x7, 0x25, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x25, 0x2, 0x2, 
    0x5d, 0x5e, 0x7, 0x14, 0x2, 0x2, 0x5e, 0x5f, 0x5, 0x1a, 0xe, 0x2, 0x5f, 
    0x60, 0x7, 0x15, 0x2, 0x2, 0x60, 0x77, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 
    0x7, 0x25, 0x2, 0x2, 0x62, 0x63, 0x7, 0x18, 0x2, 0x2, 0x63, 0x77, 0x5, 
    0x1a, 0xe, 0x2, 0x64, 0x65, 0x7, 0x25, 0x2, 0x2, 0x65, 0x67, 0x7, 0x14, 
    0x2, 0x2, 0x66, 0x68, 0x5, 0x1a, 0xe, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x69, 0x6a, 0x7, 0x15, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x18, 0x2, 0x2, 0x6b, 
    0x6c, 0x7, 0x16, 0x2, 0x2, 0x6c, 0x71, 0x5, 0x1a, 0xe, 0x2, 0x6d, 0x6e, 
    0x7, 0x22, 0x2, 0x2, 0x6e, 0x70, 0x5, 0x1a, 0xe, 0x2, 0x6f, 0x6d, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x73, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0x17, 0x2, 0x2, 
    0x75, 0x77, 0x3, 0x2, 0x2, 0x2, 0x76, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x76, 0x61, 0x3, 0x2, 0x2, 0x2, 0x76, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x77, 0xd, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 
    0x4, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x25, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x12, 
    0x2, 0x2, 0x7b, 0x7c, 0x7, 0x13, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x10, 0x9, 
    0x2, 0x7d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x83, 0x7, 0x16, 0x2, 0x2, 
    0x7f, 0x82, 0x5, 0x4, 0x3, 0x2, 0x80, 0x82, 0x5, 0x12, 0xa, 0x2, 0x81, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x86, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x87, 0x7, 0x17, 0x2, 0x2, 0x87, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x88, 0x89, 0x5, 0x14, 0xb, 0x2, 0x89, 0x8a, 0x7, 0x18, 0x2, 0x2, 
    0x8a, 0x8b, 0x5, 0x1a, 0xe, 0x2, 0x8b, 0x8c, 0x7, 0x23, 0x2, 0x2, 0x8c, 
    0xa3, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x25, 0x2, 0x2, 0x8e, 0x8f, 
    0x7, 0x12, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x13, 0x2, 0x2, 0x90, 0xa3, 0x7, 
    0x23, 0x2, 0x2, 0x91, 0xa3, 0x5, 0x10, 0x9, 0x2, 0x92, 0x93, 0x7, 0x7, 
    0x2, 0x2, 0x93, 0x94, 0x7, 0x12, 0x2, 0x2, 0x94, 0x95, 0x5, 0x16, 0xc, 
    0x2, 0x95, 0x96, 0x7, 0x13, 0x2, 0x2, 0x96, 0x99, 0x5, 0x12, 0xa, 0x2, 
    0x97, 0x98, 0x7, 0x8, 0x2, 0x2, 0x98, 0x9a, 0x5, 0x12, 0xa, 0x2, 0x99, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x9, 0x2, 0x2, 0x9c, 0x9d, 0x7, 
    0x12, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x16, 0xc, 0x2, 0x9e, 0x9f, 0x7, 0x13, 
    0x2, 0x2, 0x9f, 0xa0, 0x5, 0x12, 0xa, 0x2, 0xa0, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0xa3, 0x7, 0x23, 0x2, 0x2, 0xa2, 0x88, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x91, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x9b, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa1, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xab, 0x7, 
    0x25, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x25, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x14, 
    0x2, 0x2, 0xa7, 0xa8, 0x5, 0x1a, 0xe, 0x2, 0xa8, 0xa9, 0x7, 0x15, 0x2, 
    0x2, 0xa9, 0xab, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa4, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xab, 0x15, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xad, 0x5, 0x1a, 0xe, 0x2, 0xad, 0xae, 0x5, 0x18, 0xd, 0x2, 0xae, 0xaf, 
    0x5, 0x1a, 0xe, 0x2, 0xaf, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x9, 
    0x2, 0x2, 0x2, 0xb1, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x8, 0xe, 
    0x1, 0x2, 0xb3, 0xb4, 0x5, 0x1e, 0x10, 0x2, 0xb4, 0xb5, 0x5, 0x1a, 0xe, 
    0x6, 0xb5, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x12, 0x2, 0x2, 
    0xb7, 0xb8, 0x5, 0x1a, 0xe, 0x2, 0xb8, 0xb9, 0x7, 0x13, 0x2, 0x2, 0xb9, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbd, 0x5, 0x14, 0xb, 0x2, 0xbb, 0xbd, 
    0x7, 0x24, 0x2, 0x2, 0xbc, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xb6, 0x3, 
    0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 
    0x2, 0x2, 0xbd, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0xc, 0x7, 0x2, 
    0x2, 0xbf, 0xc0, 0x5, 0x1c, 0xf, 0x2, 0xc0, 0xc1, 0x5, 0x1a, 0xe, 0x8, 
    0xc1, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc3, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 
    0x3, 0x2, 0x2, 0x2, 0xc5, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xc8, 0x9, 0x3, 0x2, 0x2, 0xc8, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xca, 0x9, 0x4, 0x2, 0x2, 0xca, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x22, 0x24, 0x2b, 0x34, 0x3f, 0x49, 0x4e, 0x56, 0x67, 0x71, 
    0x76, 0x81, 0x83, 0x99, 0xa2, 0xaa, 0xbc, 0xc4, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

NyarParser::Initializer NyarParser::_init;
