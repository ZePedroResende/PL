#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
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
        map<string,map<string,Registo*>> indice;
        vector<string> autores;
        vector<string> titulos;
        vector<string> years;
        ofstream file;
    public:
        Authors();
        vector<string> getAutores();
        void addAutor(string);
        void addTitulo(string);
        void addYear(string);
        void addRegisto();
        void makeIndex(char*);
        void htmlStart();
        void htmlEnd();
};