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
#include <iomanip>

#define MAXN 10000005
#define ll long long
vector<int> arcos;
int arr[MAXN], case_t=0;

int calc(int acum){
  if( acum % 3 != 0 ) return 0;
  ll quart = acum/3.0;
  int tri = 0;

  for( int i = 0, j = 0; i < quart; i+=arcos[j], ++j ){
    if( arr[i] == case_t and arr[i+quart] == case_t and arr[i+(quart*2)] == case_t )
      ++tri;
  }
  
  return tri;
}

int main(){
  ll n, arco, acum;
  
  while( cin >> n ){
    arcos.clear(); case_t++; 
    arr[0] = case_t; acum = 0;
    
    for( int i = 0; i < n; ++i ){
      cin >> arco;
      arcos.push_back(arco);
      acum += arco;
      arr[acum] = case_t;
    }
    
    cout << calc(acum) << endl;
  }
  return 0;
}