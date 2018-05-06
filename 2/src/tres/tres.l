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

%x AUTHOR YEAR TITLE KEYWORD

NOME ([a-zA-Z]|[áàâãéèêíóôúçñÁÀÂÃÉÈÍÓÔÕÚÇ]|[\:\,\.]|[0-9])
YEAR [yY][eE][aA][rR]
AUTOR [aA][uU][tT][hH][oO][rR]
TITLE [tT][iI][tT][lL][eE]
KEYWORD [kK][eE][yY][wW][oO][rR][dD]
STRING [A-Za-z]

%%
{YEAR}[\ \t]*=[\ \t]*[\{\"]*            {BEGIN YEAR;}

<YEAR>(\})?(,)?                         {regs->setYear(year); 
                                        auth->addYear(year);
                                         year.clear();
                                         BEGIN 0;
                                         }

<YEAR>\n|\"|\{|\}                       ;

<YEAR>[0-9]+                            {year = year + yytext;}

{AUTOR}[\ \t]*=[\ \t]*[\{\"]+           {findN++; 
                                        if(findN==2){
                                          auth->addRegisto();
                                          regs = new Registo();
                                          findN = 0;
                                        }
                                        BEGIN AUTHOR;}

<AUTHOR>[\"\}],                         {auth->addAutor(autor);
                                        autor.clear();  
                                        BEGIN 0;
                                        }

<AUTHOR>\ |\\|\n|\{|\}|\(|\)            ;

<AUTHOR>(and[\ \n]*)+                   {auth->addAutor(autor); 
                                        autor.clear();
                                        }

<AUTHOR>{NOME}                          {autor = autor + yytext;}

[\ \t]+{TITLE}[\ \t]*=[\ \t]*[\{\"]+    {BEGIN TITLE;}

<TITLE>[\"\}],                          {regs->setTitulo(titulo);
                                        auth->addTitulo(titulo);
                                        titulo.clear();
                                        BEGIN 0;
                                        }

<TITLE>\n|\"|\{|\}|\\                   ;

<TITLE>({NOME}|\-|\ |\:|\,|\'|\\|\#|\=)+     {titulo = titulo + yytext;}


.|\n                               

%%
int main(int argc, char *argv[]) {
  FlexLexer* lexer = new yyFlexLexer;
  switch(argc){
    case 1:
      {
       cout << "Autor em falta -> Por favor indique o autor a consultar :D" << endl;
       break;
      }
    case 2:
      {
        while(lexer->yylex() != 0);
        auth->makeIndex(argv[1]);
        break;
      }
    case 3:
      {
        ifstream infile(argv[2]);
        if (infile){
          lexer->switch_streams(&infile,&cout);
          while(lexer->yylex() != 0);
          auth->makeIndex(argv[1]);
        }
        else{
          cout << "cant open file" << endl;
        }
        break;
      }
    default:
      {
        cout << "Wrong args" << endl;
        break;
      }
    }
  return 0;
}

