#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;


struct State{
  int b[3];

  int hash() const {
    return b[0] + 65*b[1] + 65*65*b[2];
  }

  bool operator < (const State &t) const {
    return hash() < t.hash();
  }
};

map<State,State> dad;
map<State,int> visited;

char buffer[1024];

void print(State act){
  vector<string> result;

  while(dad.count(act)){
    sprintf(buffer, "%4d%4d%4d\n", act.b[0], act.b[1], act.b[2]);
    result.push_back(string(buffer));
    act = dad[act];
  }
  sprintf(buffer, "%4d%4d%4d\n", act.b[0], act.b[1], act.b[2]);
  result.push_back(string(buffer));

  for( int i = result.size()-1; i>=0; i-- ){
    printf("%s",result[i].c_str());
  }
  printf("============\n");
}

void bfs(int a, int b, int c){
  State ini;
  dad.clear(); visited.clear();
  queue<State> q;

  ini.b[0]=a; ini.b[1]=b; ini.b[2]=c;
  visited[ini]=1;
  q.push(ini);
  bool solved = false;

  while(q.size()){
    State act = q.front(); q.pop();
    if(act.b[0] == act.b[1] && act.b[0] == act.b[2]){
      solved=true;
      print(act);
      break;
    }

    for( int i = 0; i < 3; ++i ){
      for( int j = 0; j < 3; ++j ){

        if(i == j) continue;
        if( act.b[i] < act.b[j] ) continue;

        State temp = act;
        temp.b[i] = temp.b[i]-act.b[j];
        temp.b[j] = temp.b[j]+act.b[j];
        if(visited.count(temp)) continue;

        visited[temp]=1;
        dad[temp]=act;

        if(temp.b[0] == temp.b[1] && temp.b[0] == temp.b[2]){
          solved=true;
          print(temp);
          break;
        }

        q.push(temp);
      }
    }
  }

  if(!solved){
    printf("%4d%4d%4d\n",ini.b[0], ini.b[1], ini.b[2]);
    printf("============\n");
  }
}

int main(){
  int a,b,c;
  while(cin >> a >> b >> c && a+b+c){
    bfs(a,b,c);
  }
  printf("%4d%4d%4d\n",0,0,0);
  printf("============\n");
  return 0;
}
