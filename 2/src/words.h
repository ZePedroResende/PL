#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include <stdio.h>

using namespace std;

class WordCounter {
  private:
    unordered_map<string,int> categorias;
    vector<pair<int, string> > catCount;
    ofstream file;
    map<string,tuple<string,string,string>> catInfo;
    void htmlStart(int);
    void htmlEnd();
    void tableStart(int);
    void tableEnd();
  public:
    WordCounter();
    void printer(int);
    static bool comparator(pair<int, string>, pair<int, string>);
    void addWord(string);
};
