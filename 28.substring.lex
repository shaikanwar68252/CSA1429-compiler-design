%{
#include <stdio.h>
%}

%%
abc    { printf("ABC"); }
.      { putchar(yytext[0]); }
%%

int yywrap() {
    return 1; // Signal the end of input
}

int main(void) {
    yylex();
    return 0;
}
