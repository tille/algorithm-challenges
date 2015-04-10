#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAXN 800
int x[MAXN];
int y[MAXN];
int p[MAXN];

struct edges{
  int to, from; 
  double weight;
  edges(int a, int b, double c): to(a), from(b), weight(c){}
};

vector<edges> graph;

bool comp(const edges &a, const edges &b ){
  return a.weight<b.weight;
}

void init(int n){
  for( int i = 0; i < n; ++i) p[i]=i;
}

int find(int u){
  return p[u]==u?u:p[u]=find(p[u]);
}

void link(int u, int v){
  int a = find(u);
  int b = find(v);
  if(a!=b) p[a]=b;
}

// ll a = max(x[temp1-1],x[temp2-1])-min(x[temp1-1],y[temp2-1]);
// ll b = max(y[temp1-1],y[temp2-1])-min(y[temp1-1],y[temp2-1]);

int main(){
  int n;
  while( cin >> n ){
    graph.clear();
    init(n);
    int temp1, temp2, m;
    for( int i = 0; i < n; ++i ) cin >> x[i] >> y[i];
    cin >> m;
    for( int i = 0; i < m; ++i ){
      cin >> temp1 >> temp2;
      link(temp1-1,temp2-1);
    }

    for( int i = 0; i < n; ++i ){
      for( int j = 0; j < n; ++j ){
        if(find(i)!=find(j)){
          int a = max(x[i],x[j])-min(x[i],x[j]);
          int b = max(y[i],y[j])-min(y[i],y[j]);
          double c = sqrt(a*a+b*b);
          graph.push_back(edges(i,j,c));
        }
      }
    }

    sort(graph.begin(), graph.end(), comp );
    double acum=0;
    for( int i = 0; i < graph.size(); ++i ){
      if( find(graph[i].to)!=find(graph[i].from) ){
        acum += graph[i].weight;
        link(graph[i].to,graph[i].from);
      }
    }
    printf("%.2f\n",acum);
  }
  return 0;
}