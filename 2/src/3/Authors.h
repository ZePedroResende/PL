#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include "Registo.h"

using namespace std;

class Authors{

    private:
        map<string,vector<Registo*>> indice;
        vector<string> autores;
        vector<string> titulos;
        vector<string> keys;
        vector<string> years;
    public:
        Authors();
        vector<string> getAutores();
        void addAutor(string);
        void addTitulo(string);
        void addKey(string);
        void addYear(string);
        void addRegisto(Registo*);
        void makeIndex(char*);
};