%{
    #include<stdio.h>
    int v=0,c=0;
%}

%%
[ \t\n]+ ;
[aeiouAEIOU] {v++;}
[^aeiouAEIOU] {c++;}
%%

int main(){
    printf("Enter the string\n");
    yylex();
    printf("Number of vowel %d\n",v);
    printf("Number of consonant %d\n",c);
    return 0;
}

int yywrap(){
    return 1;
}