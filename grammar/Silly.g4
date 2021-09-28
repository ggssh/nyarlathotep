grammar Silly;

import Lexer;

// non-terminals expressed as context-free grammar (BNF)
baseblock: (func | expr)* EOF;
func:
	funcname = IDENTIFIER LPAREN params = STRING RPAREN # FuncCall;
expr:
	left = expr op = (MUL | DIV) right = expr	# OpExpr
	| left = expr op = (ADD | SUB) right = expr	# OpExpr
	| atom = INTEGER							# AtomExpr
	| LPAREN expr RPAREN						# ParenExpr;
