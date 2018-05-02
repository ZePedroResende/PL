#include "Graph.h"

Graph::Graph(){
}

vector<string> Graph::getAuthors(string pessoas){
  vector<string> autores ;
  istringstream iss(pessoas);
  string token;
  while (std::getline(iss, token, ' ')){
    if(token.compare("and"))
      autores.push_back(token);
  }
  return autores;
}

void Graph::addCol(string pessoas){
  vector<string> autores = getAuthors(pessoas);

  switch(autores.size()){
    case 0:
      cout<< "ERROR" << endl;
      break;
    case 1:
      ++colaboracao[autores.front()][autores.front()];
      break;
    default:
      for (auto a : autores){
        for (auto b : autores){
          if(a.compare(b)){
            ++colaboracao[a][b];
          }
        }
      }
      break;
    }
}

void Graph::addColaborator(vector<string>& autores){
  switch(autores.size()){
    case 0:
      cout<< "ERROR" << endl;
      break;

    case 1:
      ++colaboracao[autores.front()][autores.front()];
      break;

    default:
      for (auto a : autores){
        for (auto b : autores){
          if(a.compare(b)){
            ++colaboracao[a][b];
          }
        }
      }
      break;
  }
}

void Graph::printColaborator(string pessoa){

  auto lista = colaboracao[pessoa];
  for (auto it : lista) {
    cout << setw(20) << pessoa <<
    setw(20) << "--" << setw(20)
    << it.first << "[label=\""
    << it.second << "\","
    << "weight=\"" << it.second
    << "\"];" << endl;

  }
}

void Graph::printRede(){

  for (auto it : colaboracao) {
    printColaborator(it.first);
  }
}

void Graph::printStartGraph(){
  cout << "strict graph {" << endl;
}

int main(){
  Graph* g = new Graph();
  vector<string> autor ;
  autor.push_back("prh") ;
  autor.push_back("jj") ;
  autor.push_back("ramalho") ;

  g->addColaborator(autor);
  g->addCol("jj");
  g->addCol("jj and ramalho");
  g->printStartGraph();
  g->printRede();
  cout << "}"<< endl;
}
