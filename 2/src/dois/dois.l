%option c++
%option noyywrap

%x dentro_categoria titulo autor

%{
#include "words.h"
TextAnalizer *ta = new TextAnalizer();
string cat = "", ttl = "", aut = "", cod = "", name = "";
%}

STRING             ([a-zA-Z]|[áàâãéèêíóôúçñÁÀÂÃÉÈÍÓÔÕÚÇ]|[\ \\\.-\]\{\}])
AUTHOR             ([aA][uU][tT][hH][oO][rR])([ \n\t]+)?=([ \n\t]+)?[\{\"]
TITLE              ([tT][iI][tT][lL][eE])([ \n\t]+)?=([ \n\t]+)?[\{\"]
END                ([\"\}],[ \t]*)
%%

\n                     ;
\@string\{             ;
\@{STRING}+\{          {yytext[yyleng-1]='\0';
                        yytext=yytext+1;
                        ta->addWord(yytext);
                        cat = yytext;
                        BEGIN(dentro_categoria);}
.                       ;

<dentro_categoria>\n                     ;
<dentro_categoria>[[:alnum:]]+[ \t]*\,   {yytext[yyleng-1]='\0';
                                          cod = yytext;}
<dentro_categoria>{TITLE}                {BEGIN (titulo);}
<dentro_categoria>{AUTHOR}               {BEGIN (autor);}
<dentro_categoria>([ \t]*)\}([ \t]*)\n   {BEGIN 0;}
<dentro_categoria>.                      ;

<autor>[\t\n]                 ;
<autor>{STRING}           {name.append(yytext);}
<autor>{END}              {aut=name;
                           name = "";
                           BEGIN (dentro_categoria);}
<autor>.                   ;

<titulo>[\t\n]                 ;
<titulo>{STRING}           {name.append(yytext);}
<titulo>{END}              {ttl = name; name = "";
                            ta -> addInfo(cod,cat,ttl,aut);
                            ttl.empty();cod.empty();cat.empty();aut.empty();
                            BEGIN 0;}
<titulo>.                   ;  

%%
int main(int argc, char *argv[]) {

  FlexLexer* lexer = new yyFlexLexer;
  switch(argc){
    case 1:
      {
        while(lexer->yylex() != 0);
        ta->printer();
        break;
      }
    case 2:
      {
        ifstream infile(argv[1]);
        if (infile){
          lexer->switch_streams(&infile,&cout);
          while(lexer->yylex() != 0);
          ta->printer();
        }
        else{
          cout << "cant open file" << endl;
        }
        break;
      }
    default:
      {
        cout << "wrong args" << endl;
        break;
      }
  }
  return 0;
}
