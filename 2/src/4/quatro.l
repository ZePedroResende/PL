%option c++
%option noyywrap
%x AUTHOR
%{
#include "Graph.h"
Graph* g = new Graph();
vector<string> names;
string  name ;
%}

autor (author|AUTHOR)([ \n\t]+)?=([ \n\t]+)?
NOME ([a-zA-Z]|á|à|â|ã|é|è|ê|í|ó|ô|ú|ç|ñ|Á|À|Â|Ã|É|È|Í|Ó|Ô|Õ|Ú|Ç)

%%
[ \n\t]                                                ;
<*>{autor}                                             BEGIN AUTHOR;
<AUTHOR>[{"]                                           ;
<AUTHOR>([ \n\t]+)and([ \n\t]*)(and)?                  { names.push_back(name); name.clear(); }
<AUTHOR>\.                                        { name.append("\\"); name.append(yytext); }
<AUTHOR>[\n\t]                                         ;
<AUTHOR>{NOME}                                         { name.append(yytext);}
<AUTHOR>([ \n\t]*)?[}"]([ \n\t]*)?,                    { names.push_back(name); name.clear(); g->addColaborator(names); names.clear();BEGIN INITIAL;}
<AUTHOR>.                                              ;
.                                                      ;
%%
int main(int argc, char *argv[]) {
  FlexLexer* lexer = new yyFlexLexer;

  switch(argc){
    case 1:
      {
        while(lexer->yylex() != 0);
        break;
      }
    case 2:
      {
        cout << argv[1] << endl;
        ifstream infile(argv[1]);
        if (infile){
          lexer->switch_streams(infile,cout);
          while(lexer->yylex() != 0);
          g->printRede();
        }
        else{
          cout << "cant open file" << endl;
        }
        break;
      }
    case 3:
      {
        ifstream infile(argv[1]);
        if (infile){
          lexer->switch_streams(infile,cout);
          while(lexer->yylex() != 0);
          if (g->isAuthor(argv[2])){
            g->printStartGraph();
            g->printColaborator(argv[2]);
            cout << "}" << endl;
          }else{
            cout << "No author with that name !";
          }
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
