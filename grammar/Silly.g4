grammar Silly;

import Lexer;

compUnit: (decl | funcDef)* EOF;
decl: constDecl | varDecl;
constDecl: CONST INT constDef (COMMA constDef)* SEMICOLON;
constDef:
	IDENTIFIER ASSIGN expr
	| IDENTIFIER LBRACK (expr)? RBRACK ASSIGN LBRACE expr (
		COMMA expr
	)* RBRACE;
varDecl: INT var (COMMA var)* SEMICOLON;
var:
	IDENTIFIER
	| IDENTIFIER LBRACK expr RBRACK
	| IDENTIFIER ASSIGN expr
	| IDENTIFIER LBRACK (expr)? RBRACK ASSIGN LBRACE expr (
		COMMA expr
	)* RBRACE;
funcDef: VOID IDENTIFIER LPAREN RPAREN block;
block: LBRACE (blockItem)* RBRACE;
blockItem: decl | stmt;
stmt:
	lVal ASSIGN expr SEMICOLON
	| IDENTIFIER LPAREN RPAREN SEMICOLON
	| block
	| IF LPAREN cond RPAREN stmt (ELSE stmt)?
	| WHILE LPAREN cond RPAREN stmt
	| SEMICOLON;
lVal: IDENTIFIER | IDENTIFIER LBRACK expr RBRACK;
cond: expr relOp expr;
relOp: EQ | NE | LT | GT | LE | GE;
expr:
	expr binOp expr
	| unaryOp expr
	| LPAREN expr RPAREN
	| lVal
	| NUMBER;
binOp: ADD | SUB | MUL | DIV | MOD;
unaryOp: ADD | SUB;