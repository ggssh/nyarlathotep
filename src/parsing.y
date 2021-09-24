%{
    #include <stdio.h>
    int yylex(void);
%}

%start Program
// , ; . :=  =
%token COMMA SEMICOLON DOT ASSIGN CONST_DEF 
// 运算符 + - * /
%token ADD SUB MUL DIV 
// 比较符 < > <= >=
%token LESS GREATER LESS_EQU GREATER_EQU
%token BEGIN END IF THEN WHILE DO CONST VAR CALL PROCEDURE ODD

// 算符优先级
%left ADD SUB
%left MUL DIV


%%
Program : BLOCK DOT ;

BLOCK : 
%%

int main()
{
    return yyparse();
}
yyerror(char *s)
{
    printf(stderr,"error:%s\n",s);
}