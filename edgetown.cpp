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

typedef long long ll;
typedef pair<int,int> p;

int visited[106];
int path[106][106];
int path2[106][106];
vector<int> graph[106];

void bfs(int start, int which ){
    memset( visited, 0, sizeof visited );
    queue<p> q;
    q.push(p(start,0));

    while( q.size() ){
        int n1 = q.front().first;
        int n2 = q.front().second;
        q.pop();

        if( !visited[n1] ){
            visited[n1] = 1;
            if( !which ) path[start][n1] = n2;
            else path2[start][n1] = n2;

            for( int i = 0; i < graph[n1].size(); ++i ){
                int temp = graph[n1][i];
                if( !visited[temp] ){
                    q.push(p(graph[n1][i],n2+1));
                }
            }
        }
    }
}

int main(){
    int n,ini,fin,a,b;
    while( scanf("%d",&n) && n ){

        for( int i = 0; i < 106; ++i ) graph[i].clear();
        for( int i = 0; i < 106; ++i ) for( int j = 0; j < 106; ++j ) path[i][j] = path2[i][j] = 1<<30;

        for( int i = 0; i < n; ++i ){
            scanf("%d",&ini);
            while( cin.peek() != '\n' ){
                cin >> fin;
                graph[ini-1].push_back(fin-1);
            }
        }

        for( int i = 0; i < n; ++i ) bfs(i,0);
        for( int i = 0; i < 106; ++i ) graph[i].clear();

        for( int i = 0; i < n; ++i ){
            scanf("%d",&ini);
            while( cin.peek() != '\n' ){
                cin >> fin;
                graph[ini-1].push_back(fin-1);
            }
        }

        for( int i = 0; i < n; ++i ) bfs(i,1);

        cin >> a >> b;

        int salir = 0;
        for( int i = 0; i < n && !salir; ++i ){
            for( int j = 0; j < n && !salir; ++j ){
                if( path2[i][j] > ((a*path[i][j])+b) ) salir = 1;
            }
        }
        if( salir ) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
