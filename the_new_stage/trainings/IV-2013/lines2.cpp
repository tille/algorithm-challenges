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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

int L,C;
map<string, int> visited;
#define ll long long

string conv(int num){
  string res = "";
  string s_num = toStr(num);
  int zeros = 3-s_num.size();
  if(!zeros) res = s_num;
  else if(zeros==1) res = "0" + s_num;
  else res = "00" + s_num;
  return res;
}

string swap_row(string state, int f1, int f2){
  f1--; f2--; 
  int pos1 = f1*C*3, pos2 = f2*C*3;
  
  string n_state = state;
  
  for( int i = 0; i < C*3; ++i ){
    n_state[pos1+i] = state[pos2+i];
    n_state[pos2+i] = state[pos1+i];      
  }
  
  return n_state;
}

string swap_col(string state, int c1, int c2){
  c1--; c2--; c1*=3; c2*=3;
  string n_state = state;

  for( int i = 0; i < L*C*3; i += C*3){    
    n_state[c1+i] = state[c2+i];
    n_state[c1+i+1] = state[c2+i+1];
    n_state[c1+i+2] = state[c2+i+2];

    n_state[c2+i] = state[c1+i];
    n_state[c2+i+1] = state[c1+i+1];
    n_state[c2+i+2] = state[c1+i+2];
  }
  
  return n_state;
}

int bfs(string ini, string fin){
  queue<string> q; 
  queue<int> cont;
  visited.clear();
  
  q.push(ini); 
  cont.push(0);
  int ans = 0;
  
  while( q.size() ){
    string act = q.front(); q.pop();
    int ans = cont.front(); cont.pop();
    //cout << "--" << act << endl;
    visited[act] = 1;
    
    if(act == fin) return ans;
  
    for( int i = 1; i < L; ++i ){
      for( int j = i+1; j <= L; ++j ){
        string next = swap_row(act, i, j);
        if( next == fin ) return ans+1;
        //cout << "**" << next << endl;
        
        if( !visited[next] ){
          q.push(next);
          cont.push(ans+1);
          //visited[next] = 1;
        }
      }
    }
    
    for( int i = 1; i < C; ++i ){
      for( int j = i+1; j <= C; ++j ){
        string next = swap_col(act, i, j);
        if( next == fin ) return ans+1;
        //cout << "??" << next << endl;
        
        if( !visited[next] ){
          q.push(next); 
          cont.push(ans+1);
          //visited[next] = 1;
        }
      }
    }
  }  
  
  return ans;
}

int main(){  
  int num;
  string fin, ini; 
  
  while( cin >> L >> C){
    fin = ini = "";
    
    for( int i = 0; i < L*C; ++i ){
      scanf("%d",&num);
      fin += conv(num);
    }
    
    for( int i = 1; i <= L*C; ++i ){
      ini += conv(i);
    }
    
    int ans = bfs(ini, fin);
    
    if( !ans ) printf("*\n");
    else printf("%d\n",ans);
  }
  
  return 0;
}