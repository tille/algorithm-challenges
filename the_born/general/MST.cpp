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

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

typedef long long ll;

struct edge{
  int start, end, weight;
  edge( ){}
  edge( int a, int b, int c ) : start(a), end(b), weight(c){}
  bool operator < ( const edge &that ) const{
    return weight < that.weight;
  }
};

vector<edge> e;
int n, m, y, j ,k;

//////////////// UNION-FIND by Andres Mejia////////////////////

int p[100003], rank[100003];
void make_set( int x ){ p[x] = x, rank[x] = 0; }
void link( int x, int y ){
  if( rank[x] > rank[y] ) p[y] = x;
  else{ p[x] = y; if( rank[x] == rank[y] ) rank[y]++; }
}
int find_set( int x ){
  return x != p[x] ? p[x] = find_set(p[x]) : p[x] ;
}
void merge( int x, int y ){ link(find_set(x), find_set(y)); }

///////////////////////////////////////////////////////////////


ll kruskal( int n ){
  ll total = 0;
  sort( e.begin(), e.end() );
  for ( int i = 0; i<=n ; ++i ) make_set(i);
  for ( int i = 0; i< e.size(); ++i ) {
    int u = e[i].start, v = e[i].end, w = e[i].weight;
    if(find_set(u) != find_set(v)){
      total += w;
      merge(u, v);
    }
  }
  return total;
}


int main(){
  while( cin >> n >> m ){
    for ( int i = 0; i<m ; ++i ) {
      cin >> y >> j >> k;
      e.push_back( edge(y,j,k) );
    }
    cout << kruskal(n) << endl;
  }
  return 0;
}
