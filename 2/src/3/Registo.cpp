#include "Registo.h"

Registo::Registo(){

}

Registo::Registo(string t, string k, string y){
    titulo = t;
    keyword = k;
    year = y;
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

string Registo::getYear(){
    return year;
}

string Registo::getKey(){
    return keyword;
}

string Registo::getTitulo(){
    return titulo;
}
