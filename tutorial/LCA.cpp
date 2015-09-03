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

#define SIZE 100004
#define SIZE2 20

typedef long long ll;

int dp[SIZE][SIZE2];
int t[SIZE];
ll cost[SIZE];
int prof[SIZE];
ll path[SIZE];
int loga;

void table(int n) {
  for (int j = 1; (1 << j) < n; ++j)
    for (int i = 0; i < n; i++)
      if( dp[i][j - 1] != -1 ) dp[i][j] = dp[dp[i][j - 1]][j - 1];
}

int query(int p, int q) {
  if (prof[p] < prof[q]) swap(p,q);
  for (loga = 1; (1 << loga) <= prof[p]; ++loga); loga--;

  for (int i = loga; i >= 0; i--)
    p = (prof[p] - (1 << i) >= prof[q])? dp[p][i] : p;

  if (p == q) return p;

  for (int i = loga; i >= 0; i--)
    if( dp[p][i] != -1 && dp[p][i] != dp[q][i] )
      p = dp[p][i], q = dp[q][i];

  return t[p];
}

int main(){
  int n,a,q,s,b,lca; ll l;
  t[0] = -1, cost[0] = prof[0] = path[0] = 0;
  
  while( cin >> n && n ){
    memset(dp,-1,sizeof dp);
    
    for( int i = 1; i < n; ++i ){
      scanf("%d%lli",&a,&l);
      t[i] = a, cost[i] = l, prof[i] = prof[a] + 1;
      path[i] = path[a] + cost[i];
      dp[i][0] = a;
    }
    table(n);
    
    cin >> q;
    for( int i = 0; i < q; ++i ){
      if( i ) printf(" ");
      scanf("%d%d",&s,&b);
      lca = query(s,b);
      printf("%lli",path[s]-path[lca] + path[b]-path[lca]);
    }
    printf("\n");
  }
  return 0;
}