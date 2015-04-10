#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

#define SIZE 10004

struct edge{
  int to, weight;
  edge(){}
  edge(int t,int w) :to(t),weight(w){}
  bool operator < (const edge &that) const{
    return weight > that.weight;
  }
};

vector<edge> graph[SIZE];
int dist[SIZE];

void dijkstra(int a, int b, int n){
  for( int i=0;i<=n;++i) dist[i]=1<<30;
  
  priority_queue<edge> q;
  q.push(edge(a,0));
  dist[a] = 0;
  
  while(q.size()){
    int node = q.top().to;
    int weight = q.top().weight;
    q.pop();
    
    if( weight > dist[node] ) continue;
    if( node == b ) break;
    
    for( int i = 0; i < graph[node].size(); ++i ){
      int next = graph[node][i].to;
      int tot_weight = weight + graph[node][i].weight;
      if( tot_weight < dist[next] ){
        dist[next] = tot_weight;
        q.push(edge(next,dist[next]));
      }
    }
    
  }
}

int main(){
  int t,p,n,nr,cost,r;
  string city,name1,name2;
  scanf("%d",&t);
  
  while(t--){
    map<string,int> names;
    scanf("%d",&n);
    
    for( int i = 1; i <= n; ++i ){
      cin >> city >> p;
      names[city] = i;
      graph[i].clear();
      
      while(p--){
        scanf("%d %d",&nr,&cost);
        graph[i].push_back(edge(nr,cost));
      }
    }
    
    scanf("%d",&r);
    while(r--){
      cin >> name1 >> name2;
      int n1 = names.find(name1)->second;
      int n2 = names.find(name2)->second;
      dijkstra(n1,n2,n);
      printf("%d\n",dist[n2]);
    }
  }
  return 0;
}