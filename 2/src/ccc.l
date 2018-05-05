%option c++	
%option noyywrap

%{
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<memory>

#include "Authors.h"

int findN=0;
string autor="", titulo="", year="", keyword="";
Authors* auth = new Authors();
Registo* regs = new Registo();

%}

%x CATEGORY AUTHOR TITLE YEAR KEYWORD

NOME ([a-zA-Z]|\á|à|â|ã|é|è|ê|í|ó|ô|ú|ç|ñ|Á|À|Â|Ã|É|È|Í|Ó|Ô|Õ|Ú|Ç|:|,)
YEAR [yY][eE][aA][rR]
AUTOR [aA][uU][tT][hH][oO][rR]
TITLE [tT][iI][tT][lL][eE]
KEYWORD [kK][eE][yY][wW][oO][rR][dD]

%%
{YEAR}[\ \t]*=[\ \t]*[\{\"]*            {BEGIN YEAR;}

<YEAR>(\})?(,)?                         {regs->setYear(year); year.clear(); BEGIN 0;}

<YEAR>\n|\"|\{|\}                       ;

<YEAR>[0-9]+                            {year = year + yytext;}

{AUTOR}[\ \t]*=[\ \t]*[\{\"]+           {BEGIN AUTHOR;}

<AUTHOR>[\"\}],                         {auth->addAutor(autor); autor.clear(); auth->addRegisto(regs); BEGIN 0;}

<AUTHOR>\ |\\|\n|\{|\}|\(|\)            ;

<AUTHOR>(and[\ \n]*)+                   {auth->addAutor(autor); autor.clear();}

<AUTHOR>({NOME}|\.)+                    {autor = autor + yytext;}

{KEYWORD}[\ \t]*=[\ \t]*[\{\"]          {BEGIN KEYWORD;}

<KEYWORD>[\"\}]                         {regs->setKey(keyword); keyword.clear(); BEGIN 0;}

<KEYWORD>\n|\"|\{|\}|\+|\=|\.|\?|\\|\$  ;

<KEYWORD>{NOME}+                        {keyword = keyword + yytext;}

(\ )*{TITLE}[\ \t]*=[\ \t]*[\{\"]+      {BEGIN TITLE;}

<TITLE>[\"\}],                          {regs->setTitulo(titulo); titulo.clear(); BEGIN 0;}

<TITLE>\n|\"|\{|\}|\\                   ;

<TITLE>[a-zA-Z0-9\-\ :\,\'\\\#]+        {titulo = titulo + yytext;}


.|\n

%%
int main(int argc, char *argv[]) {
  FlexLexer* lexer = new yyFlexLexer;
  while(lexer->yylex() != 0);
  auth->makeIndex();
  return 0;
}