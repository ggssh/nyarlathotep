lexer grammar Lexer;

// tokens expressed as regular expressions keywords
INT: 'int';
VOID: 'void';
RETURN: 'return';
CONST: 'const';
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
ASSIGN: '=';
NOT: '!';
LT: '<';
LE: '<=';
GT: '>';
GE: '>=';
EQ: '==';
NE: '!=';
AND: '&&';
OR: '||';

// others
COMMA: ',';
SEMICOLON: ';';
NUMBER: [0-9]+; // 整型
IDENTIFIER: [_a-zA-Z][0-9a-zA-Z]*; //标识符
STRING: '"' (ESC | .)*? '"'; // 匹配字符串
WHITESPACE: [ \t\r\n]+ -> skip;
INLINE_COMMENT: '//' .*? '\r'? '\n' -> skip;
// NEWLINE: '\r'? '\n'; // 换行

fragment ESC: '\\"' | '\\\\';