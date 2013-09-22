using namespace std;
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
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

int L,C;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

struct state{
  string state_id;
  vector<int> values;

  state(vector<int>& final){
    values = final;
    state_id = "x";
  }
  
  bool operator==(const state &that) const{ 
    bool ans = true;
    for( int i = 0; i < values.size(); ++i ){
      if( that.values[i] != values[i] ) return false;
    }
    return true;
  }
  
  string get_id(){
    if(state_id!="x") return state_id;
    int res = 0;
    for( int i = 0; i < values.size(); ++i ){ 
      res*=10; res+=values[i];
    }
    state_id = toStr(res);
    return state_id;
  }
  
  state swap_r(int f1, int f2){
    f1--; f2--; int pos1 = f1*C, pos2 = f2*C;
    string cpy_id = state_id;
    vector<int> temp; temp = values;
    
    for( int i = 0; i < C; ++i ){
      int tempo = temp[pos1+i];
      temp[pos1+i] = temp[pos2+i];
      temp[pos2+i] = tempo;

      cpy_id[pos1+i] = state_id[pos2+i];
      cpy_id[pos2+i] = state_id[pos1+i];      
    }
    state res(temp); res.state_id = cpy_id;
    return res;
  }

  state swap_c(int c1, int c2){
    c1--; c2--; string cpy_id = state_id;
    vector<int> temp; temp = values;
    for( int i = 0; i < temp.size(); i += C){
      int tempo = temp[i+c1];
      temp[i+c1] = temp[i+c2];
      temp[i+c2] = tempo;
      
      cpy_id[c1+i] = state_id[c2+i];
      cpy_id[c2+i] = state_id[c1+i];      
    }
    state res(temp); res.state_id = cpy_id;
    return res;
  }

};

map<string, int> visited;

int bfs(state &ini, state &fin){
  queue<state> q; 
  queue<int> cont;
  visited.clear();
  q.push(ini); cont.push(0);
  int ans = 0;
  
  while( q.size() ){
    state act = q.front(); q.pop();
    int ans = cont.front(); cont.pop();
    //cout << "--" << act.get_id() << endl;
    visited[act.state_id] = 1;
    
    if(act == fin) return ans;
  
    for( int i = 1; i < L; ++i ){
      for( int j = i+1; j <= L; ++j ){
        // trocar fila i con fila j
        state next = act.swap_r(i,j);
        //cout << "**" << next.get_id() << endl;
        
        if( !visited[next.get_id()] ){
          q.push(next); 
          cont.push(ans+1);
          //visited[next.get_id()] = 1;
        }
      }
    }
    
    for( int i = 1; i < C; ++i ){
      for( int j = i+1; j <= C; ++j ){
        // trocar column i con columna j
        state next = act.swap_c(i,j);
        //cout << "??" << next.get_id() << endl;
        
        if( !visited[next.get_id()] ){
          q.push(next); 
          cont.push(ans+1);
          //visited[next.get_id()] = 1;
        }
      }
    }
  }  
  
  return ans;
}

int main(){  
  int num, final_id = 0, initial_id = 0;
  
  while( cin >> L >> C ){
    vector<int> final;
    for( int i = 0; i < L; ++i ){
      for( int j = 0; j < C; ++j ){
        scanf("%d",&num);
        final.push_back(num);
        final_id *= 10;
        final_id += num;
      }
    }
        
    vector<int> initial;
    for( int i = 1; i <= final.size(); ++i ){
      initial.push_back(i);
      initial_id *= 10;
      initial_id += num;      
    }
    
    state fin(final); fin.state_id = toStr(final_id);
    state ini(initial); ini.state_id = toStr(initial_id);
    
    int ans = bfs(ini, fin);
    
    if( !ans ) printf("*\n");
    else printf("%d\n",ans);
  }
  
  return 0;
}