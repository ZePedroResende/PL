%option c++	
%option noyywrap

%{
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<memory>

#include "Authors.h"

using namespace std;

int findN=0;
string autor = "", titulo="", year="", keyword="";
Authors* auth = new Authors();
Registo* regs = new Registo();

%}

%x AUTHOR TITLE YEAR KEYWORD

NOME ([a-zA-Z]|á|à|â|ã|é|è|ê|í|ó|ô|ú|ç|ñ|Á|À|Â|Ã|É|È|Í|Ó|Ô|Õ|Ú|Ç|:|,)
YEAR [yY][eE][aA][rR]

%%
author[\ \t]*=[\ \t]*[\{\"]+            {BEGIN AUTHOR;}

AUTHOR[\ \t]*=[\ \t]*[\{\"]+            {BEGIN AUTHOR;}

(\ )*title[\ \t]*=[\ \t]*[\{\"]         {BEGIN TITLE;}

(\ )*TITLE[\ \t]*=[\ \t]*[\{\"]         {BEGIN TITLE;}

(\ )+{YEAR}[\ \t]*=[\ \t]*[\{\"]*       {BEGIN YEAR;}

keyword[\ \t]*=[\ \t]*[\{\"]            {BEGIN KEYWORD;}

<AUTHOR>[\"\}],                         {auth->addAutor(autor); autor.clear(); BEGIN 0;}

<AUTHOR>\ |\n|\{|\}|\\|\(|\)                ;

<AUTHOR>(and[\ \n]*)+                   {auth->addAutor(autor); autor.clear();}

<AUTHOR>{NOME}+                         {autor = autor + yytext; }

<TITLE>[\"\}],                          {auth->addTitulo(titulo); titulo.clear(); BEGIN 0;}

<TITLE>\n|\"|\{|\}                      ;

<TITLE>[a-zA-Z0-9\-\ :\,\'\\\#]+        {titulo = titulo + yytext;}

<YEAR>(\})?,                            {auth->addYear(year); year.clear(); BEGIN 0;}

<YEAR>\n|\"|\{|\}|\+|\=|\.|\,|\(|\)     ;

<YEAR>[0-9]+                            {year = year + yytext;}

<KEYWORD>[\"\}]                         {auth->addKey(keyword); keyword.clear(); BEGIN 0;}

<KEYWORD>\n|\"|\{|\}|\+|\=|\.|\?|\\|\$                   ;

<KEYWORD>{NOME}+                        {keyword = keyword + yytext;}

.|\n	                                  ;

%%
int main(int argc, char *argv[]) {

  FlexLexer* lexer = new yyFlexLexer;
  while(lexer->yylex() != 0);
  //auth->makeIndex();
  return 0;
}