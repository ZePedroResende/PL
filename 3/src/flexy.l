%x mean syn english word

%{
#include <stdio.h>
%}

STRING ([a-zA-Z0-9]|[áàâãéèêíóôõúçñÁÀÂÃÉÈÍÓÔÕÚÇ,-.]|\ )

%option noyywrap
%%
{STRING}+\{                                   {yytext[yyleng-1]='\0';
                                               printf("\nWORD: %s\n", yytext);
                                               BEGIN (word);}

<word>\}                                      {BEGIN 0;
                                               }

<word>\n                                      ;

<word>[\ \t]*mean:[\ \t]*\"                   {BEGIN (mean);}

<mean>\"                                      {BEGIN (word);}

<mean>{STRING}+                               {printf("MEAN: %s\n", yytext);}

<word>[\ \t]*syn:[\ \t]*\"                    {BEGIN (syn);}

<syn>\"                                       {BEGIN (word);}

<syn>\n                                       ;

<syn>{STRING}+                                {printf("SYN: %s\n", yytext);}

<word>[\ \t]*english:[\ \t]*\"                {BEGIN (english);}

<english>\"                                   {BEGIN (word);}

<english>\n                                   ;

<english>{STRING}+                            {printf("ENGLISH: %s\n", yytext);}

.|\n                                          ;
%%
/*int main(int argc, char *argv[]) {
    int s;
    while(s=yylex()){
        printf("%d\n",s);
    }
    
    return 0;
}*/
