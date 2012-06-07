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
typedef pair<int,int> various;

int Out, Out1, Out2, t, x, y;
double len1, len2, sum, dist;
vector<various> coordenates;
int visited[1003];


int bfs(){
    queue<various> q;
    q.push( various(Out1-1, 0) );
    while( q.size() ){
        int here = q.front().first;
        int nivel = q.front().second;
        q.pop();

        if( here == Out2-1 ) return nivel;
        if( !visited[here] ){
            visited[here] = 1;
            for ( int i = 0; i< Out; ++i ) {
                if( !visited[i] ){
                    int x1 = (abs(coordenates[here].first-coordenates[i].first)*abs(coordenates[here].first-coordenates[i].first));
                    int y1 = (abs(coordenates[here].second -coordenates[i].second))*(abs(coordenates[here].second -coordenates[i].second) );
                    dist = sqrt(x1 + y1);
                    if( dist <= sum ) q.push( various( i, nivel+1 ) );
                }
            }
        }
    }
    return -1;
}


int main(){
  cin >> t;
  while( t-- ){
      coordenates.clear();
      scanf("%d %d %d %lf %lf",&Out, &Out1, &Out2, &len1, &len2);
      for ( int i = 0; i< Out; ++i ) {
          scanf("%d %d",&x,&y);
          coordenates.push_back( various(x,y) );
      }
      memset(visited,0,sizeof(visited));
      sum = double(double(len1) + double(len2));
      int tales = bfs();
      if( tales == -1 ) cout << "Impossible" << endl;
      else cout << tales << endl;
  }
  return 0;
}
