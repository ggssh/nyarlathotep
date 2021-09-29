lexer grammar Lexer;

// tokens expressed as regular expressions keywords
INT: 'int';
VOID: 'void';
RETURN: 'return';
IF: 'if';
ELSE: 'else';
WHILE: 'while';
FOR: 'for';
BREAK: 'break';
CONTINUE: 'continue';

// operator
ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
MOD: '%';
LPAREN: '(';
RPAREN: ')';
LBRACK: '[';
RBRACK: ']';
LBRACE: '{';
RBRACE: '}';
LT: '<';
LE: '<=';
GT: '>';
GE: '>=';
EQ: '==';
NE: '!=';
AND: '&&';
OR: '||';

// others
INTEGER: [0-9]+; // 整型
IDENTIFIER: [_a-zA-Z][0-9a-zA-Z]*; //标识符
STRING: '"' (ESC | .)*? '"'; // 匹配字符串
WS: [ \t\r\n] -> skip;
INLINE_COMMENT: '//' .*? '\r'? '\n' -> skip;
// NEWLINE: '\r'? '\n'; // 换行

fragment ESC: '\\"' | '\\\\';