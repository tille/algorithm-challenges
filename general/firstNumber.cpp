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
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); \
x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

typedef long long ll;

string sequence = "";
string text = "";
string p = "";

void init(){
    for( long i = 1; i < 100002; ++i ){
        text += toStr(i);
    }
}

void Kmp2( long *kmpNext ){
  int i,j;
  i = j = 0;
  bool salir = true;
   while (j < text.size() && salir){
      while (i > -1 && p[i] != text[j] && salir) i = kmpNext[i];
      i++; j++;
      if (i >= p.size()){
         printf("%d\n",(j-i)+1);
         i = kmpNext[i];
         salir = false;
      }
   }
}

void preKmp( long *b ){
    ll i = 0, j = -1;
    b[ i ] = j;
    while( i<p.size() ){
        while( j>=0 && p[i] != p[j] ) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

long h;

int main(){
  init();
  cin >> h;
  p = toStr(h);
  long b[ p.size()+1 ];
  preKmp( b );
  Kmp2( b );
  return 0;
}
