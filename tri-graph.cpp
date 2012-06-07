using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <queue>

typedef long long ll;
typedef pair<int,int> edge;

long paths[300000];
int visited[300000];
vector<edge> nodes[300000];

int dijkstra( int a, int b ){
    priority_queue<edge, vector<edge>, greater<edge> > q;
    q.push( edge( a, 0 ) );

    while( q.size() ){
        int here = q.top().first;
        int weight = q.top().second;
        q.pop();
        if( !visited[here] ){
            paths[here] = weight;
            visited[here] = 1;
            if( here == b ) return weight;
            for( int i = 0; i < nodes[here].size(); ++i ){
                int t = nodes[here][i].first;
                long w = nodes[here][i].second;
                if( visited[ t ] == 0 ) q.push( edge( t , w+weight ) );
            }
        }
    }
    return paths[ b ];
}

int main(){

  int n, num, i1, tot, cases = 0, num2, num3;
  while(scanf("%d",&n) && n){
    for( int i = 0; i < n; ++i ){

        cin >> num >> num2 >> num3;
        i1 = (i*3)+1;
        nodes[i1].clear(); nodes[i1+1].clear(); nodes[i1+2].clear();
        visited[i1] = visited[i1+1] = visited[i1+2] = 0;
        nodes[i1].push_back( edge(i1+1,num) );
        nodes[i1+1].push_back( edge(i1+2,num2) );

        if( i != (n-1) ){
            nodes[i1].push_back( edge(i1+3,num) );
            nodes[i1].push_back( edge(i1+4,num) );
            nodes[i1+1].push_back( edge(i1+3,num2) );
            nodes[i1+1].push_back( edge(i1+4,num2) );
            nodes[i1+1].push_back( edge(i1+5,num2) );
            nodes[i1+2].push_back( edge(i1+4,num3) );
            nodes[i1+2].push_back( edge(i1+5,num3) );
        }else tot = num2;

    }
    printf("%d. %d\n",++cases,dijkstra(2,(n*3)-1)+tot);

  }
  return 0;
}
