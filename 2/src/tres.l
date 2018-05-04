%option c++	
%option noyywrap

%{
#include<stdio.h>
#include<stdlib.h>
#include<cstring>

#include "Authors.h"

using namespace std;

int findN=0;
string autor = "", titulo="", book="";
Authors* auth = new Authors();
Registo* regs = new Registo();

%}

%x CATEGORY AUTHOR TITLE BOOKTITLE NOTE ADDRESS YEAR 

STRING [a-zA-z|ú|à|á|â|é|í|ç|ã|ì|õ|.]

%%
author[\ \t]*=[\ \t]*[\{\"]+        {BEGIN AUTHOR;}

AUTHOR[\ \t]*=[\ \t]*[\{\"]+        {BEGIN AUTHOR;}

(\ )*title[\ \t]*=[\ \t]*[\{\"]     {BEGIN TITLE;}

(\ )*TITLE[\ \t]*=[\ \t]*[\{\"]     {BEGIN TITLE;}

booktitle[\ \t]*=[\ \t]*[\{\"]     {BEGIN BOOKTITLE;}

BOOKTITLE[\ \t]*=[\ \t]*[\{\"]     {BEGIN BOOKTITLE;}

<AUTHOR>[\"\}],                                    {auth->addAutor(autor); autor=""; BEGIN 0;}

<AUTHOR>\ |\n|\{|\}|(\\)                           ;

<AUTHOR>(and[\ \n]*)+                              {auth->addAutor(autor); autor="";}

<AUTHOR>{STRING}+                                  {autor = autor + yytext;}

<TITLE>[\"\}],                                     {auth->addTitulo(titulo); titulo=""; BEGIN 0;}

<TITLE>\}                                          {titulo = titulo + yytext;}

<TITLE>[a-zA-Z0-9\-\ :\,\'\\\#\{]+                 {titulo = titulo + yytext;}

<TITLE>\n|\"                                       ;

<BOOKTITLE>[\"\}],                                 {auth->addBook(book); book.clear(); BEGIN 0;}

<BOOKTITLE>\}                                      {cout << yytext << endl; book.append(yytext);}

<BOOKTITLE>[a-zA-Z0-9\-\ :\,'\\\#\{\$]+           {cout << yytext << endl; book.append(yytext);}

<BOOKTITLE>\n|\"                                   ;

.|\n	                                             ;

%%
int main(int argc, char *argv[]) {

  FlexLexer* lexer = new yyFlexLexer;
  while(lexer->yylex() != 0);
  //auth->makeIndex();
  return 0;
}