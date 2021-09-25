
// Generated from src/MyGrammar.g4 by ANTLR 4.9


#include "MyGrammarListener.h"
#include "MyGrammarVisitor.h"

#include "MyGrammarParser.h"


using namespace antlrcpp;
using namespace antlr4;

MyGrammarParser::MyGrammarParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MyGrammarParser::~MyGrammarParser() {
  delete _interpreter;
}

std::string MyGrammarParser::getGrammarFileName() const {
  return "MyGrammar.g4";
}

const std::vector<std::string>& MyGrammarParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MyGrammarParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ExprContext ------------------------------------------------------------------

MyGrammarParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MyGrammarParser::ExprContext::getRuleIndex() const {
  return MyGrammarParser::RuleExpr;
}

void MyGrammarParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AtomExprContext ------------------------------------------------------------------

tree::TerminalNode* MyGrammarParser::AtomExprContext::INT() {
  return getToken(MyGrammarParser::INT, 0);
}

MyGrammarParser::AtomExprContext::AtomExprContext(ExprContext *ctx) { copyFrom(ctx); }

void MyGrammarParser::AtomExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomExpr(this);
}
void MyGrammarParser::AtomExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomExpr(this);
}

antlrcpp::Any MyGrammarParser::AtomExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyGrammarVisitor*>(visitor))
    return parserVisitor->visitAtomExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

MyGrammarParser::ExprContext* MyGrammarParser::ParenExprContext::expr() {
  return getRuleContext<MyGrammarParser::ExprContext>(0);
}

MyGrammarParser::ParenExprContext::ParenExprContext(ExprContext *ctx) { copyFrom(ctx); }

void MyGrammarParser::ParenExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenExpr(this);
}
void MyGrammarParser::ParenExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenExpr(this);
}

antlrcpp::Any MyGrammarParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyGrammarVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OpExprContext ------------------------------------------------------------------

std::vector<MyGrammarParser::ExprContext *> MyGrammarParser::OpExprContext::expr() {
  return getRuleContexts<MyGrammarParser::ExprContext>();
}

MyGrammarParser::ExprContext* MyGrammarParser::OpExprContext::expr(size_t i) {
  return getRuleContext<MyGrammarParser::ExprContext>(i);
}

MyGrammarParser::OpExprContext::OpExprContext(ExprContext *ctx) { copyFrom(ctx); }

void MyGrammarParser::OpExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpExpr(this);
}
void MyGrammarParser::OpExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpExpr(this);
}

antlrcpp::Any MyGrammarParser::OpExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyGrammarVisitor*>(visitor))
    return parserVisitor->visitOpExpr(this);
  else
    return visitor->visitChildren(this);
}

MyGrammarParser::ExprContext* MyGrammarParser::expr() {
   return expr(0);
}

MyGrammarParser::ExprContext* MyGrammarParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MyGrammarParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MyGrammarParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 0;
  enterRecursionRule(_localctx, 0, MyGrammarParser::RuleExpr, precedence);

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
    setState(8);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyGrammarParser::INT: {
        _localctx = _tracker.createInstance<AtomExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(3);
        dynamic_cast<AtomExprContext *>(_localctx)->atom = match(MyGrammarParser::INT);
        break;
      }

      case MyGrammarParser::T__4: {
        _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(4);
        match(MyGrammarParser::T__4);
        setState(5);
        expr(0);
        setState(6);
        match(MyGrammarParser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(18);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(16);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<OpExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(10);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(11);
          dynamic_cast<OpExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MyGrammarParser::T__0

          || _la == MyGrammarParser::T__1)) {
            dynamic_cast<OpExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(12);
          dynamic_cast<OpExprContext *>(_localctx)->right = expr(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<OpExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(13);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(14);
          dynamic_cast<OpExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MyGrammarParser::T__2

          || _la == MyGrammarParser::T__3)) {
            dynamic_cast<OpExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(15);
          dynamic_cast<OpExprContext *>(_localctx)->right = expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(20);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool MyGrammarParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 0: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MyGrammarParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MyGrammarParser::_decisionToDFA;
atn::PredictionContextCache MyGrammarParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MyGrammarParser::_atn;
std::vector<uint16_t> MyGrammarParser::_serializedATN;

std::vector<std::string> MyGrammarParser::_ruleNames = {
  "expr"
};

std::vector<std::string> MyGrammarParser::_literalNames = {
  "", "'*'", "'/'", "'+'", "'-'", "'('", "')'"
};

std::vector<std::string> MyGrammarParser::_symbolicNames = {
  "", "", "", "", "", "", "", "INT"
};

dfa::Vocabulary MyGrammarParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MyGrammarParser::_tokenNames;

MyGrammarParser::Initializer::Initializer() {
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
    0x3, 0x9, 0x18, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xb, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x13, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0x16, 0xb, 0x2, 0x3, 0x2, 0x2, 0x3, 0x2, 0x3, 0x2, 0x2, 
    0x4, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x5, 0x6, 0x2, 0x19, 0x2, 0xa, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x5, 0x8, 0x2, 0x1, 0x2, 0x5, 0xb, 0x7, 0x9, 0x2, 
    0x2, 0x6, 0x7, 0x7, 0x7, 0x2, 0x2, 0x7, 0x8, 0x5, 0x2, 0x2, 0x2, 0x8, 
    0x9, 0x7, 0x8, 0x2, 0x2, 0x9, 0xb, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4, 0x3, 
    0x2, 0x2, 0x2, 0xa, 0x6, 0x3, 0x2, 0x2, 0x2, 0xb, 0x14, 0x3, 0x2, 0x2, 
    0x2, 0xc, 0xd, 0xc, 0x6, 0x2, 0x2, 0xd, 0xe, 0x9, 0x2, 0x2, 0x2, 0xe, 
    0x13, 0x5, 0x2, 0x2, 0x7, 0xf, 0x10, 0xc, 0x5, 0x2, 0x2, 0x10, 0x11, 
    0x9, 0x3, 0x2, 0x2, 0x11, 0x13, 0x5, 0x2, 0x2, 0x6, 0x12, 0xc, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xf, 0x3, 0x2, 0x2, 0x2, 0x13, 0x16, 0x3, 0x2, 
    0x2, 0x2, 0x14, 0x12, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x15, 0x3, 0x3, 0x2, 0x2, 0x2, 0x16, 0x14, 0x3, 0x2, 0x2, 0x2, 
    0x5, 0xa, 0x12, 0x14, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MyGrammarParser::Initializer MyGrammarParser::_init;
