#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class F {
public:
    bool operator()(pair<int, string> left, pair<int, string> right) {
        if (left.first > right.first) return true;
        if (left.first == right.first && left.second < right.second) return true;
        return false;
    }
};
