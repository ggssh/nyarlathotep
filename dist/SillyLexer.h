
// Generated from Silly.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"




class  SillyLexer : public antlr4::Lexer {
public:
  enum {
    INT = 1, VOID = 2, RETURN = 3, CONST = 4, IF = 5, ELSE = 6, WHILE = 7, 
    FOR = 8, BREAK = 9, CONTINUE = 10, ADD = 11, SUB = 12, MUL = 13, DIV = 14, 
    MOD = 15, LPAREN = 16, RPAREN = 17, LBRACK = 18, RBRACK = 19, LBRACE = 20, 
    RBRACE = 21, ASSIGN = 22, NOT = 23, LT = 24, LE = 25, GT = 26, GE = 27, 
    EQ = 28, NE = 29, AND = 30, OR = 31, COMMA = 32, SEM = 33, INTEGER = 34, 
    IDENTIFIER = 35, STRING = 36, WS = 37, INLINE_COMMENT = 38
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

