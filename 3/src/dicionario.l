%x mean syn english word

%{
#include <stdio.h>
#include "y.tab.h"
%}

STRING ([a-zA-Z0-9]|[áàâãéèêíóôõúçñÁÀÂÃÉÈÍÓÔÕÚÇ,-.]|\ )

%option noyywrap
%%
{STRING}+\{                                   {yytext[yyleng-1]='\0';
                                               yylval.texto = strdup(yytext);
                                               BEGIN (word); return WORD;}

<word>\}                                      {BEGIN 0;
                                               }

<word>\n                                      ;

<word>[\ \t]*mean:[\ \t]*\"                   {BEGIN (mean);}

<mean>\"                                      {BEGIN (word);}

<mean>{STRING}+                               {yylval.texto = strdup(yytext);
                                               return MEAN;}

<word>[\ \t]*syn:[\ \t]*\"                    {BEGIN (syn);}

<syn>\"                                       {BEGIN (word);}

<syn>\n                                       ;

<syn>{STRING}+                                {yylval.texto = strdup(yytext); 
                                               return SYN;}

<word>[\ \t]*english:[\ \t]*\"                {BEGIN (english);}

<english>\"                                   {BEGIN (word);}

<english>\n                                   ;

<english>{STRING}+                            {yylval.texto = strdup(yytext);   
                                               return ENGLISH;}

.|\n                                          ;
%%
/*int main(int argc, char *argv[]) {
    int s;
    while(s=yylex()){
        printf("%d\n",s);
    }
    
    return 0;
}*/
