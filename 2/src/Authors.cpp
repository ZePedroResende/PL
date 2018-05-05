#include "Authors.h"

Authors::Authors(){

}

vector<string> Authors::getAutores(){
    return autores;
}

void Authors::addAutor(string a){
    autores.push_back(a);
}

void Authors::addTitulo(string a){
    titulos.push_back(a);
}

void Authors::addKey(string a){
    keys.push_back(a);
}

void Authors::addYear(string a){
    years.push_back(a);
}

void Authors::addRegisto(Registo* r){
    for(string s: autores){
        indice.insert(pair<string,Registo*>(s,r));
    }
}

void Authors::makeIndex(){
    cout << "-------------- AUTORES ---------------" << endl;
    for(int i=0; i<autores.size(); i++){
        cout << autores.at(i) << endl;
    }
    cout << "----------- ANOS ---------------" << endl;
    for(int i=0; i<years.size(); i++){
        cout << years.at(i) << endl;
    }
    cout << "------------ KEYWORDS -------------" << endl;
    for(int i=0; i<keys.size(); i++){
        cout << keys.at(i) << endl;
    }
    cout << "--------------- TITLES ---------------" << endl;
    for(int i=0; i<titulos.size(); i++){
        cout << titulos.at(i) << endl;
    }
    
}