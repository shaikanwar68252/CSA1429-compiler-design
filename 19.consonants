%{
int count = 0;
%}

%%
[aeiouAEIOU]   { count++; }
[0-9]          { count++; }
.              ;
%%

int main() {
    yylex();
    printf("Number of constants: %d\n", count);
    return 0;
}

int yywrap() {
    return 1;
}
