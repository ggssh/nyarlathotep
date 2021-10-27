grammar Nyar;

import Lexer;

compUnit: (decl | funcDef)* EOF;
decl: constDecl | varDecl;
constDecl: CONST INT constDef (COMMA constDef)* SEMICOLON;
constDef:
	IDENTIFIER ASSIGN expr
	| IDENTIFIER LBRACK (expr)? RBRACK ASSIGN LBRACE expr (
		COMMA expr
	)* RBRACE;
varDecl: INT varDef (COMMA varDef)* SEMICOLON;
varDef:
	IDENTIFIER
	| IDENTIFIER LBRACK expr RBRACK
	| IDENTIFIER ASSIGN expr
	| IDENTIFIER LBRACK (expr)? RBRACK ASSIGN LBRACE expr (COMMA expr)* RBRACE;
funcDef: VOID IDENTIFIER LPAREN RPAREN block;
block: LBRACE (decl | stmt)* RBRACE;
//blockItem: decl | stmt;
stmt:
	lVal ASSIGN expr SEMICOLON // 赋值语句
	| IDENTIFIER LPAREN RPAREN SEMICOLON // 函数调用
	| block // 块
	| IF LPAREN cond RPAREN stmt (ELSE stmt)? // if 语句
	| WHILE LPAREN cond RPAREN stmt // while语句
	| SEMICOLON; // 空
lVal: IDENTIFIER | IDENTIFIER LBRACK expr RBRACK; // left value
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