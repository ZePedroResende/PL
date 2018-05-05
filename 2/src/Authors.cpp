#include "Authors.h"

Authors::Authors(){

}

vector<string> Authors::getAutores(){
    return autores;
}

void Authors::addAutor(string a){
    autores.push_back(a);
    autores.clear();
}

void Authors::addTitulo(string a){
    titulos.push_back(a);
    titulos.clear();
}

void Authors::addKey(string a){
    keys.push_back(a);
    keys.clear();
}

void Authors::addYear(string a){
    years.push_back(a);
     for(int i=0; i<years.size(); i++){
        cout << years.at(i) << endl;
    }
    years.clear();
}

void Authors::makeIndex(){
    
}