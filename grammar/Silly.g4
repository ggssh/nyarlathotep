grammar Silly;

import Lexer;

// the unit of a compile
compUnit: (decl | funcDef)* EOF;
// funcDef: funcname = IDENTIFIER LPAREN params = STRING RPAREN # FuncCall; expr: left = expr op =
// (MUL | DIV) right = expr # OpExpr | left = expr op = (ADD | SUB) right = expr # OpExpr | atom =
// INTEGER # AtomExpr | LPAREN expr RPAREN # ParenExpr;
decl: constDecl | varDecl;
constDecl: CONST bType constDef (COMMA constDef) SEM;
// base type
bType: INT;
constDef:
	IDENTIFIER (LBRACK constExp RBRACK) ASSIGN constInitVal;
constInitVal:
	constExp
	| LBRACE (constInitVal (COMMA constInitVal))? RBRACE;

varDecl: bType varDef (COMMA varDef) SEM;
varDef:
	IDENTIFIER (LBRACK constExp RBRACK)*
	| IDENTIFIER (LBRACK constExp RBRACK)* ASSIGN initVal;
initVal: expr
        | LBRACE (initVal (COMMA initVal))? RBRACE;
// constExp: LPAREN RPAREN;
funcDef: funcType IDENTIFIER LPAREN (funcFParams)? RPAREN block;
funcType: VOID | INT;
funcFParams: funcFParam (COMMA funcFParam);
funcFParam:
	bType IDENTIFIER (LBRACK RBRACK (LBRACK expr RBRACK)*)?;
block: LBRACE (blockItem)* RBRACE;
blockItem: decl | stmt;
stmt:
	lVal ASSIGN expr SEM
	| (expr)? SEM
	| block
	| IF LPAREN cond RPAREN stmt (ELSE stmt)?
	| WHILE LPAREN cond RPAREN stmt
	| BREAK SEM
	| CONTINUE SEM
	| RETURN (expr)? SEM;
expr: addExp;
cond: lOrExp;
lVal: IDENTIFIER (LBRACK expr RBRACK)*;
primaryExp: LPAREN expr RPAREN
        | lVal
        | number;
number: INTEGER;
unaryExp:
	primaryExp
	| IDENTIFIER LPAREN (funcRParams)? RPAREN
	| unaryOp unaryExp;
unaryOp: ADD | SUB | NOT;
funcRParams: expr (COMMA expr)*;
mulExp: unaryExp
        | mulExp op = (MUL | DIV | MOD) unaryExp;
addExp: mulExp
        | addExp (ADD | SUB) mulExp;
relExp: addExp
        | relExp (LT | GT | LE | GE) addExp;
eqExp: relExp
        | eqExp (EQ | NE) relExp;
lAndExp: eqExp
        | lAndExp AND eqExp;
lOrExp: lAndExp
        | lOrExp OR lAndExp;
constExp: addExp;
