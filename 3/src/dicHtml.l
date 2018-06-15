%option noyywrap

%x mean syn english word

%{
#include <stdio.h>
#include"htmlDic.h"
#include"lexDicHtml.h"
char* w,m,s,e;
FILE *fp;
%}

STRING ([a-zA-Z0-9]|[áàâãéèêíóôõúçñÁÀÂÃÉÈÍÓÔÕÚÇ,-.]|\ )

%option noyywrap
%%
{STRING}+\{                                   {yytext[yyleng-1]='\0';
                                               addWord(fp, yytext); 
                                               BEGIN (word);}

<word>\}                                      {BEGIN 0;
                                               }

<word>\n                                      ;

<word>[\ \t]*mean:[\ \t]*\"                   {BEGIN (mean);}

<mean>\"                                      {BEGIN (word);}

<mean>{STRING}+                               {strcpy(m, yytext);
                                               addMean(fp, yytext);}

<word>[\ \t]*syn:[\ \t]*\"                    {BEGIN (syn);}

<syn>\"                                       {BEGIN (word);}

<syn>\n                                       ;

<syn>{STRING}+                                {strcpy(s,yytext);
                                               addSyn(fp, yytext);}

<word>[\ \t]*english:[\ \t]*\"                {BEGIN (english);}

<english>\"                                   {BEGIN (word);}

<english>\n                                   ;

<english>{STRING}+                            {strcpy(e,yytext);
                                               addEnglish(fp, yytext);}

.|\n                                          ;
%%

void goHtml(char* argv){
    fp = fopen("../html/dic.html", "w");
    beginHtml(fp);
    yylex();
    endHtml(fp);
}
