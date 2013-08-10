#include <iostream>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

struct node{
  int x, y, w;
  node() { }
  node ( int nx ,int ny, int nw ) : x(nx), y(ny), w(nw) {}
};

struct edge{
  int to, weight;
  edge() { }
  edge ( int t ,int w ) : to(t), weight(w){}
};

char reading[ 1002 ][ 1002 ];
int graph[ 1002 ][ 1002 ];

node dfs( node s, int f, int c ){
    stack<node> p;
    p.push( s );
    node mayor = s;
    int cont =0;

    while( p.size() ){
        node actual = p.top();
        graph[ actual.x ][ actual.y ] = 1;
        //cout << actual.w << " ";
        if( actual.w > mayor.w ) mayor = actual;
        p.pop();
        int x = actual.x;
        int y = actual.y;
        int w = actual.w;
        if( (y-1) > -1 && reading[ x ][ y-1 ] == '.' && graph[ x ][ y-1 ] == 0 ) p.push( node( x, y-1, w+1 ) );
        if( (y+1) < c && reading[ x ][ y+1 ] == '.' && graph[ x ][ y+1 ] == 0 ) p.push( node( x, y+1, w+1 ) );
        if( (x-1) > -1 && reading[ x-1 ][ y ] == '.' && graph[ x-1 ][ y ] == 0 ) p.push( node( x-1, y, w+1 ) );
        if( (x+1) < f && reading[ x+1 ][ y ] == '.' && graph[ x+1 ][ y ] == 0 ) p.push( node( x+1, y, w+1 ) );
    }

    return mayor;
}

int t, c, f;
char character;
node uNode;

int main(){
    scanf("%d",&t);
    while( t-- ){
        scanf("%d %d",&c, &f);
        for( int i = 0; i < f; ++i ){
            for( int a = 0; a < c; ++a ){
                cin >> character;
                reading[ i ][ a ] = character;
                graph[ i ][ a ] = 0;
                if( character == '.' ){
                    uNode = node( i, a, 1 );
                }
            }
        }

    node start = dfs( uNode, f, c );
    for( int i = 0; i < f; ++i ) for( int a = 0; a < c; ++a ) graph[ i ][ a ] = 0;
    node retry = node( start.x, start.y, 1 );
    node result = dfs( retry, f, c );
    cout << "Maximum rope length is " << result.w-1 << "." << endl;

    }
    return 0;
}
