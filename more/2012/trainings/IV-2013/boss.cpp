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

#define MAXN 502

vector<int> graph[MAXN];
int ages[MAXN];
int visited[MAXN];

int bfs(int n1){  
  queue<int> q;
  q.push(n1);
  int ans = 1<<30;
  if( !graph[n1].size() ) return ans;
  
  while( q.size() ){
    int act = q.front();
    visited[act] = 1;
    q.pop();
    
    if(ages[act] < ans and act!=n1) ans=ages[act];

    for( int i = 0; i< graph[act].size(); ++i ){
      int next = graph[act][i];
      if( !visited[next] ){
        q.push(next);
        visited[next] = 1;
      }
    }
  }  
  
  return ans;
}

int main(){
  int N,M,I,age,x,y;
  while( cin >> N >> M >> I ){
    for( int i=0; i<N; ++i ){
      cin >> age;
      ages[i] = age;
      graph[i].clear();
    }

    for( int i=0; i<M; ++i ){
      cin >> x >> y;
      graph[y-1].push_back(x-1);
    }
       
    for( int i=0; i<I; ++i ){
      char query;
      cin >> query;
      if(query == 'T'){

        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;

        // swap
        vector<int> temp = graph[n1];
        graph[n1] = graph[n2];
        graph[n2] = temp;

        for( int i=0; i<N; ++i ){
          for( int j=0; j<graph[i].size(); ++j ){
            if(graph[i][j] == n1) graph[i][j] = n2;
            else if(graph[i][j] == n2) graph[i][j] = n1;
          }
        }
       
      }else{
        memset(visited, 0, sizeof visited);
        int n1;
        cin >> n1; n1--;
        int ans = bfs(n1);
        if(ans == 1<<30) cout << '*';
        else cout << ans;
        cout << endl;
      }
    }
  }
  return 0;
}