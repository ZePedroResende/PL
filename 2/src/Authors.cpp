#include "Authors.h"

Authors::Authors(){

}

vector<string> Authors::getAutores(){
    return autores;
}

void Authors::addAutor(string a){
    autores.push_back(a);

    for(int i=0; i<autores.size(); ++i){
        //cout << autores.at(i) << endl;
    }
    autores.clear();
}

void Authors::addTitulo(string a){
    titulos.push_back(a);

    for(int i=0; i<titulos.size(); ++i){
        //cout << titulos.at(i) << endl;
    }
    titulos.clear();
}

void Authors::addBook(string a){
    books.push_back(a);

    for(int i=0; i<books.size(); ++i){
        //cout << books.at(i) << endl;
    }
    books.clear();
}

void Authors::makeIndex(){
    
}