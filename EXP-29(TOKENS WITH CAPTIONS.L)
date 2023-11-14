%{
#include <stdio.h>
%}

%%
abc    { printf("Token: ABC\n"); }
def    { printf("Token: DEF\n"); }
.      { printf("Unrecognized token: %s\n", yytext); }
%%

int yywrap() {
    return 1; // Signal the end of input
}

int main(void) {
    yylex();
    return 0;
}
