#include<map>
#include<vector>

using namespace std;

class Graph{
map<string, map<string,int>> colaboracao;

public:

vector<string> getAuthors(string pessoas);


void addColaborator();

void printColaborator(string pessoa);

void printRede();

};
