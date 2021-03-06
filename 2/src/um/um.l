%option c++
%option noyywrap
%{
#include "words.h"
WordCounter *wc = new WordCounter();
%}

STRING             [a-zA-Z]

%%

[ \n\t]                 ;
\@{STRING}+/(\{)        {yytext=yytext+1;wc->addWord(yytext);}
.                       ;

%%
int main(int argc, char *argv[]) {

  FlexLexer* lexer = new yyFlexLexer;
   switch(argc){
    case 1:
      {
        while(lexer->yylex() != 0);
        wc->printer();
        break;
      }
    case 2:
      {
        ifstream infile(argv[1]);
        if (infile){
          lexer->switch_streams(&infile,&cout);
          while(lexer->yylex() != 0);
          wc->printer();
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
