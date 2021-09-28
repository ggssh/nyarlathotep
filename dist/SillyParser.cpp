
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


//----------------- BaseblockContext ------------------------------------------------------------------

SillyParser::BaseblockContext::BaseblockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SillyParser::BaseblockContext::EOF() {
  return getToken(SillyParser::EOF, 0);
}

std::vector<SillyParser::FuncContext *> SillyParser::BaseblockContext::func() {
  return getRuleContexts<SillyParser::FuncContext>();
}

SillyParser::FuncContext* SillyParser::BaseblockContext::func(size_t i) {
  return getRuleContext<SillyParser::FuncContext>(i);
}

std::vector<SillyParser::ExprContext *> SillyParser::BaseblockContext::expr() {
  return getRuleContexts<SillyParser::ExprContext>();
}

SillyParser::ExprContext* SillyParser::BaseblockContext::expr(size_t i) {
  return getRuleContext<SillyParser::ExprContext>(i);
}


size_t SillyParser::BaseblockContext::getRuleIndex() const {
  return SillyParser::RuleBaseblock;
}

void SillyParser::BaseblockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBaseblock(this);
}

void SillyParser::BaseblockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBaseblock(this);
}


antlrcpp::Any SillyParser::BaseblockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitBaseblock(this);
  else
    return visitor->visitChildren(this);
}

SillyParser::BaseblockContext* SillyParser::baseblock() {
  BaseblockContext *_localctx = _tracker.createInstance<BaseblockContext>(_ctx, getState());
  enterRule(_localctx, 0, SillyParser::RuleBaseblock);
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
    setState(10);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SillyParser::LPAREN)
      | (1ULL << SillyParser::INTEGER)
      | (1ULL << SillyParser::IDENTIFIER))) != 0)) {
      setState(8);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SillyParser::IDENTIFIER: {
          setState(6);
          func();
          break;
        }

        case SillyParser::LPAREN:
        case SillyParser::INTEGER: {
          setState(7);
          expr(0);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(12);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(13);
    match(SillyParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncContext ------------------------------------------------------------------

SillyParser::FuncContext::FuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SillyParser::FuncContext::getRuleIndex() const {
  return SillyParser::RuleFunc;
}

void SillyParser::FuncContext::copyFrom(FuncContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncCallContext ------------------------------------------------------------------

tree::TerminalNode* SillyParser::FuncCallContext::LPAREN() {
  return getToken(SillyParser::LPAREN, 0);
}

tree::TerminalNode* SillyParser::FuncCallContext::RPAREN() {
  return getToken(SillyParser::RPAREN, 0);
}

tree::TerminalNode* SillyParser::FuncCallContext::IDENTIFIER() {
  return getToken(SillyParser::IDENTIFIER, 0);
}

tree::TerminalNode* SillyParser::FuncCallContext::STRING() {
  return getToken(SillyParser::STRING, 0);
}

SillyParser::FuncCallContext::FuncCallContext(FuncContext *ctx) { copyFrom(ctx); }

void SillyParser::FuncCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncCall(this);
}
void SillyParser::FuncCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncCall(this);
}

antlrcpp::Any SillyParser::FuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitFuncCall(this);
  else
    return visitor->visitChildren(this);
}
SillyParser::FuncContext* SillyParser::func() {
  FuncContext *_localctx = _tracker.createInstance<FuncContext>(_ctx, getState());
  enterRule(_localctx, 2, SillyParser::RuleFunc);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = dynamic_cast<FuncContext *>(_tracker.createInstance<SillyParser::FuncCallContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(15);
    dynamic_cast<FuncCallContext *>(_localctx)->funcname = match(SillyParser::IDENTIFIER);
    setState(16);
    match(SillyParser::LPAREN);
    setState(17);
    dynamic_cast<FuncCallContext *>(_localctx)->params = match(SillyParser::STRING);
    setState(18);
    match(SillyParser::RPAREN);
   
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


size_t SillyParser::ExprContext::getRuleIndex() const {
  return SillyParser::RuleExpr;
}

void SillyParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AtomExprContext ------------------------------------------------------------------

tree::TerminalNode* SillyParser::AtomExprContext::INTEGER() {
  return getToken(SillyParser::INTEGER, 0);
}

SillyParser::AtomExprContext::AtomExprContext(ExprContext *ctx) { copyFrom(ctx); }

void SillyParser::AtomExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomExpr(this);
}
void SillyParser::AtomExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomExpr(this);
}

antlrcpp::Any SillyParser::AtomExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitAtomExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode* SillyParser::ParenExprContext::LPAREN() {
  return getToken(SillyParser::LPAREN, 0);
}

SillyParser::ExprContext* SillyParser::ParenExprContext::expr() {
  return getRuleContext<SillyParser::ExprContext>(0);
}

tree::TerminalNode* SillyParser::ParenExprContext::RPAREN() {
  return getToken(SillyParser::RPAREN, 0);
}

SillyParser::ParenExprContext::ParenExprContext(ExprContext *ctx) { copyFrom(ctx); }

void SillyParser::ParenExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenExpr(this);
}
void SillyParser::ParenExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenExpr(this);
}

antlrcpp::Any SillyParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OpExprContext ------------------------------------------------------------------

std::vector<SillyParser::ExprContext *> SillyParser::OpExprContext::expr() {
  return getRuleContexts<SillyParser::ExprContext>();
}

SillyParser::ExprContext* SillyParser::OpExprContext::expr(size_t i) {
  return getRuleContext<SillyParser::ExprContext>(i);
}

tree::TerminalNode* SillyParser::OpExprContext::MUL() {
  return getToken(SillyParser::MUL, 0);
}

tree::TerminalNode* SillyParser::OpExprContext::DIV() {
  return getToken(SillyParser::DIV, 0);
}

tree::TerminalNode* SillyParser::OpExprContext::ADD() {
  return getToken(SillyParser::ADD, 0);
}

tree::TerminalNode* SillyParser::OpExprContext::SUB() {
  return getToken(SillyParser::SUB, 0);
}

SillyParser::OpExprContext::OpExprContext(ExprContext *ctx) { copyFrom(ctx); }

void SillyParser::OpExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpExpr(this);
}
void SillyParser::OpExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SillyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpExpr(this);
}

antlrcpp::Any SillyParser::OpExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SillyVisitor*>(visitor))
    return parserVisitor->visitOpExpr(this);
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
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, SillyParser::RuleExpr, precedence);

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
    setState(26);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SillyParser::INTEGER: {
        _localctx = _tracker.createInstance<AtomExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(21);
        dynamic_cast<AtomExprContext *>(_localctx)->atom = match(SillyParser::INTEGER);
        break;
      }

      case SillyParser::LPAREN: {
        _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(22);
        match(SillyParser::LPAREN);
        setState(23);
        expr(0);
        setState(24);
        match(SillyParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(36);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(34);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<OpExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(28);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(29);
          dynamic_cast<OpExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == SillyParser::MUL

          || _la == SillyParser::DIV)) {
            dynamic_cast<OpExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(30);
          dynamic_cast<OpExprContext *>(_localctx)->right = expr(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<OpExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(31);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(32);
          dynamic_cast<OpExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == SillyParser::ADD

          || _la == SillyParser::SUB)) {
            dynamic_cast<OpExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(33);
          dynamic_cast<OpExprContext *>(_localctx)->right = expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(38);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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
    case 2: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SillyParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

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
  "baseblock", "func", "expr"
};

std::vector<std::string> SillyParser::_literalNames = {
  "", "'int'", "'void'", "'return'", "'if'", "'else'", "'while'", "'for'", 
  "'break'", "'continue'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", 
  "'['", "']'", "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", 
  "'&&'", "'||'"
};

std::vector<std::string> SillyParser::_symbolicNames = {
  "", "INT", "VOID", "RETURN", "IF", "ELSE", "WHILE", "FOR", "BREAK", "CONTINUE", 
  "ADD", "SUB", "MUL", "DIV", "MOD", "LPAREN", "RPAREN", "LBRACK", "RBRACK", 
  "LBRACE", "RBRACE", "LT", "LE", "GT", "GE", "EQ", "NE", "AND", "OR", "INTEGER", 
  "IDENTIFIER", "STRING", "WS", "INLINE_COMMENT"
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
    0x3, 0x23, 0x2a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xb, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0xe, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x1d, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x25, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x28, 
    0xb, 0x4, 0x3, 0x4, 0x2, 0x3, 0x6, 0x5, 0x2, 0x4, 0x6, 0x2, 0x4, 0x3, 
    0x2, 0xe, 0xf, 0x3, 0x2, 0xc, 0xd, 0x2, 0x2b, 0x2, 0xc, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0xb, 0x5, 0x4, 0x3, 0x2, 0x9, 0xb, 0x5, 0x6, 0x4, 0x2, 0xa, 0x8, 0x3, 
    0x2, 0x2, 0x2, 0xa, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb, 0xe, 0x3, 0x2, 0x2, 
    0x2, 0xc, 0xa, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x3, 0x2, 0x2, 0x2, 0xd, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0xe, 0xc, 0x3, 0x2, 0x2, 0x2, 0xf, 0x10, 0x7, 
    0x2, 0x2, 0x3, 0x10, 0x3, 0x3, 0x2, 0x2, 0x2, 0x11, 0x12, 0x7, 0x20, 
    0x2, 0x2, 0x12, 0x13, 0x7, 0x11, 0x2, 0x2, 0x13, 0x14, 0x7, 0x21, 0x2, 
    0x2, 0x14, 0x15, 0x7, 0x12, 0x2, 0x2, 0x15, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x17, 0x8, 0x4, 0x1, 0x2, 0x17, 0x1d, 0x7, 0x1f, 0x2, 0x2, 0x18, 
    0x19, 0x7, 0x11, 0x2, 0x2, 0x19, 0x1a, 0x5, 0x6, 0x4, 0x2, 0x1a, 0x1b, 
    0x7, 0x12, 0x2, 0x2, 0x1b, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x16, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x18, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x1f, 0xc, 0x6, 0x2, 0x2, 0x1f, 0x20, 0x9, 0x2, 0x2, 
    0x2, 0x20, 0x25, 0x5, 0x6, 0x4, 0x7, 0x21, 0x22, 0xc, 0x5, 0x2, 0x2, 
    0x22, 0x23, 0x9, 0x3, 0x2, 0x2, 0x23, 0x25, 0x5, 0x6, 0x4, 0x6, 0x24, 
    0x1e, 0x3, 0x2, 0x2, 0x2, 0x24, 0x21, 0x3, 0x2, 0x2, 0x2, 0x25, 0x28, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x7, 0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x7, 0xa, 0xc, 0x1c, 0x24, 0x26, 
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
