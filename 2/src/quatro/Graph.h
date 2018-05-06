#include<map>
#include<vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace std;

class Graph{

map<string, map<string,int>> colaboracao;

public:

Graph();

vector<string> getAuthors(string pessoas);

void addCol(string pessoas);

bool isAuthor(string autor);

void addColaborator(vector<string>& autores);

void printColaborator(string pessoa);

void printRede();

void printStartGraph();

};
