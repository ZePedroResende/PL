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
        if(indice.count(s)>0){
            if(std::find(indice[s].begin(), indice[s].end(), r) == indice[s].end()){
                indice[s].push_back(r);
            }
        }
        else{
            vector<Registo*> reg;
            reg.push_back(r);
            indice.insert(pair<string,vector<Registo*>>(s,reg));
        }
        
    }
    autores.clear();
}

void Authors::makeIndex(char* autor){
    /*for(map<string,vector<Registo*>>::const_iterator it = indice.begin(); it != indice.end(); ++it){
        cout << it->first << endl;
        for(vector<Registo*>::const_iterator v = it->second.begin(); v!= it->second.end(); ++v){
            cout << " --> TITULO: " << (*v)->getTitulo() << endl;
            cout << " --> ANO: " << (*v)->getYear() << endl;
        }
    }*/

    string aut = (string) autor;
    map<string,vector<Registo*>>::const_iterator m = indice.find(aut);
    if(m == indice.end()){
        cout << "Autor não encontrado!" << endl;
    }
    else{
        vector<Registo*> v = m->second;
        cout << "---------------- REGISTOS DE " << aut << " -------------------" << endl;
        int i = 1;
        for(Registo* r : v){
            cout << " --------- REGISTO " << i << " --------- " << endl;
            cout << " --> TITULO: " << r->getTitulo() << endl;
            cout << " --> ANO: " << r->getYear() << endl;
            
            cout << "\n" << endl;
            i++;
        }
    }
    
}