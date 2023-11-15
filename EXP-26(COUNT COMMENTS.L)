%{
#include <stdio.h>
%}

%%
"/*"    { in_comment = 1; }
.|\n    { if (in_comment) printf("Comment: %s", yytext); }
"*/"    { if (in_comment) in_comment = 0; }
%%

int yywrap() {
    return 1; // Signal the end of input
}

int main(void) {
    int in_comment = 0; // Flag to track if inside a comment
    yylex();
    return 0;
}
