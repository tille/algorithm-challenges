using namespace std;
#include <iostream>
#include <vector>
#define MAXN 101

struct edge(){
}

vector<edge> graph[MAXN];

int main(){
  while( cin >> n >> m ){
    cin >> i >> j >> t;
    graph[i].push_back( edge(j,t) );
    graph[j].push_back( edge(i,t*-1) );
  }
  return 0;
}