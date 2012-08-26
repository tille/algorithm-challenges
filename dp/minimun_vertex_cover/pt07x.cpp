#include <iostream>
#include <vector>

using namespace std;

#define SIZE 100002
#define pb push_back

vector<int> graph[SIZE];
int dp[SIZE][2];
int visited[SIZE];

int f(int u, bool m){
  int r1,r2,act;
  r1=r2=0; visited[u]=1;
  
  if( graph[u].size() == 1 && visited[graph[u][0]] == 1 ){ 
    visited[u] = 0;
    return m?0:1;
  }
  
  for( int i = 0; i < graph[u].size(); ++i ){
    act = graph[u][i];
    if( visited[act] ) continue;
    r1 += (dp[act][1] != -1)? dp[act][1] : dp[act][1] = f(act,true);
  }
  
  if(!m){
    visited[u]=0;
    return r1+1;
  }
  
  for( int i = 0; i < graph[u].size(); ++i ){
    act = graph[u][i];
    if( visited[act] ) continue;
    r2 += (dp[act][0] != -1)? dp[act][0] : dp[act][0] = f(act,false);
  }
  
  visited[u]=0;  
  return min(r1+1,r2);
}

int main(){
  int n,a,b;
  cin >> n;
  memset(dp,-1,sizeof dp);
  memset(visited,0,sizeof visited);
  
  for( int i = 0; i < n-1; ++i ){
    cin >> a >> b;
    graph[a].pb(b);
    graph[b].pb(a);
  }
  
  cout << f(1,true) << endl;
  return 0;
}