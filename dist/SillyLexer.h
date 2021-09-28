
// Generated from Silly.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"




class  SillyLexer : public antlr4::Lexer {
public:
  enum {
    INT = 1, VOID = 2, RETURN = 3, IF = 4, ELSE = 5, WHILE = 6, FOR = 7, 
    BREAK = 8, CONTINUE = 9, ADD = 10, SUB = 11, MUL = 12, DIV = 13, MOD = 14, 
    LPAREN = 15, RPAREN = 16, LBRACK = 17, RBRACK = 18, LBRACE = 19, RBRACE = 20, 
    LT = 21, LE = 22, GT = 23, GE = 24, EQ = 25, NE = 26, AND = 27, OR = 28, 
    INTEGER = 29, IDENTIFIER = 30, STRING = 31, WS = 32, INLINE_COMMENT = 33
  };

  explicit SillyLexer(antlr4::CharStream *input);
  ~SillyLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

