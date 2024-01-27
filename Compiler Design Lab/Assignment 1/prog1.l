%{
  #include<stdio.h>
%}

%%

[0-9]+ { printf("%s is number \n",yytext); }
[a-zA-Z]+ { printf("%s is word \n",yytext); }
.           { /* Ignore other characters */ }

%%

int main(){
  printf("Enter the string\n");
  yylex();
  return 0;
}

int yywrap(){
  return 1;
}