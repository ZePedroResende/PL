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
        string titulo;
        string year;

    public:
        Registo();
        Registo(string,string);
        void setYear(string);
        void setTitulo(string);
        string getYear();
        string getTitulo();
};