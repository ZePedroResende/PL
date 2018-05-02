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

class WordCounter {
  private:
    unordered_map<string,int> categorias;
    vector<pair<int, string> > catCount;
    void htmlStart();
    void htmlEnd();
  public:
    WordCounter();
    void printer();
    static bool comparator(pair<int, string>, pair<int, string>);
    void addWord(string);
};
