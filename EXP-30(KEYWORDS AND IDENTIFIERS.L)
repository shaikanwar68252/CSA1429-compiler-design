%{
#include <stdio.h>
%}

%%
if      { printf("Keyword: if\n"); }
else    { printf("Keyword: else\n"); }
while   { printf("Keyword: while\n"); }
[[:alpha:]]+[[:alnum:]_]*  { printf("Identifier: %s\n", yytext); }
.       { /* Ignore other characters */ }
%%

int yywrap() {
    return 1; // Signal the end of input
}

int main(void) {
    yylex();
    return 0;
}
