#include "Registo.h"

Registo::Registo(){

}

Registo::Registo(string a, string t, string p, string y){
    titulo = t;
    autor = a;
    keyword = p;
    year = y;
}

void Registo::setAutor(string a){
    autor = a;
}

void Registo::setYear(string ano){
    year = ano;
}

void Registo::setKey(string k){
    keyword = k;
}

void Registo::setTitulo(string t){
    titulo = t;
}