%{
    #include<stdio.h>
    int i=0;
%}

%%
    
%%

int main(){
    printf("Hello world\n");
    return 0;
}

int yywrap(){
    return 1;
}