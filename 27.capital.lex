%{
%}
%%
[a-z] printf("%c",yytext[0] - ('a' - 'A'));
%%
int yywrap(){}
int main()
{
printf("Enter : ");
yylex();
printf("\n");
return 0;
}
