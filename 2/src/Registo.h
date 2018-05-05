#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <stdio.h>

using namespace std;

class Registo{

    private:
        string autor;
        string titulo;
        string keyword;
        string year;

    public:
        Registo();
        Registo(string,string,string,string);
        void setAutor(string);
        void setYear(string);
        void setKey(string);
        void setTitulo(string);
};