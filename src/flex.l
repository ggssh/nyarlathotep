%{
    int chars = 0;
    int words = 0;
    int lines = 0;

%}

%%
[a-zA-Z]+   {words++;chars+=strlen(yytext);}
\n          {chars++;lines++;}
.           {chars++;}
%%

int main(int argc, char **argv) {
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    }else{
        yyin = stdin;
    }

    yylex();

    printf("lines : %d  words : %d  chars : %d\n", lines, words, chars);

    return 0;
}