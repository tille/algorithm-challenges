#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

vector<int> nums[10006];
int visited[10006];
int path[10006];

int dfs( int t ){

  stack<int> p;
  p.push( t );
  int mayor = t;

  while( p.size() ){
    int h = p.top();
    visited[h] = 1;
    p.pop();

    if( path[h] > path[mayor] ) mayor = h;

    for( int i = 0; i < nums[h].size(); ++i ){
      if( !visited[nums[h][i]] ){
        p.push(nums[h][i]);
        path[nums[h][i]] = path[h]+1;
      }
    }
  }
  return mayor;
}

int main(){
  int t, u, v, last;
  while( scanf("%d",&t) != EOF ){

    int longest = t; last = -1;
    for(int i = 0; i < t+2; ++i ) nums[i].clear();

    for( int j = 1; j<t; ++j ){
      scanf("%d",&u); scanf("%d",&v);
      if( u == v ) continue;
      nums[ u ].push_back( v );
      nums[ v ].push_back( u );
      last = v;
    }

    if( last == -1 ) printf("%d\n",0);
    else{
      // 2 Dfs, The first for search the node more longest and the second for search the longest path in the tree
      for( int i = 0; i<longest+3; ++i ) visited[i] = path[i] = 0;
      int start = dfs( 1 );
      for( int i = 0; i<longest+3; ++i ) visited[i] = path[i] = 0;
      int retry = dfs( start );
      printf("%d\n",path[retry]);
    }
  }
  return 0;
}
