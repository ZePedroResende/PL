#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
//using namespace std;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;
using std::cout;
using std::endl;
class F {
public:
    bool operator()(pair<int, string> left, pair<int, string> right) {
        if (left.first > right.first) return true;
        if (left.first == right.first && left.second < right.second) return true;
        return false;
    }
};
