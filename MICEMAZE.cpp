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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " es " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y, double tol = EPS)
{ return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

//cuando se va a trabajar con enteros la suma es con 5 y no con 0.5
double round(double x){ return floor(x*100+0.5)/100; }

bool myfunction (int i,int j) { return (i>j); }

long long reverse_num( ll sourcenum ){
    ll temp = sourcenum;
    ll sum = 0;
    while ( temp ){
      sum *= 10;
      sum += temp%10;
      temp /= 10;
    }
    return sum;
}

int graph[102][102];
int N,E,T,M,a,b,w;

int floyd(){
    for (int k = 1; k<=N;++k){
        for (int i = 1; i<=N;++i){
            for (int j = 1; j<=N;++j){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
}

int main(){
    int cont = 0;
    for( int i = 0; i < 102; ++i ){
        for( int j = 0; j < 102; ++j ){
            if( i == j ) graph[i][j] = 0;
            else graph[i][j] = 1000000;
        }
    }
	scanf("%d %d %d %d",&N,&E,&T,&M);
	for( int i = 0; i < M; ++i ){
        scanf("%d %d %d",&a,&b,&w);
        graph[a][b] = w;
	}
	floyd();
	for( int i = 1; i <= N; ++i ) if( graph[i][E]<=T ) cont++;
	cout << cont << endl;
    return 0;
}
