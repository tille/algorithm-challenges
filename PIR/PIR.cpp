#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 5  // tamaño de la matriz de determinante
#define MAXNT 5 // tamaño determinante si es 5x5 estara seteado a 5

#define ll long long

double AB, AC, AD, BC, BD, CD;
double m[MAXN][MAXN];
double tree[MAXNT];

void add(int i,int k){
  for(; i < MAXNT; i += i&-i ) tree[i] += k;
}

ll get(ll i){
  ll s = 0;
  for(; i > 0; i-=i&-i) s+=tree[i];
  return s;
}

int parity(vector<int> v){
  ll tot;
  memset( tree,0,sizeof tree );
  tot = 0;

  for( int j = v.size()-1; j > -1; --j ){
    add(v[j],1);
    tot += get(v[j]-1); 
  }
  int sign = (tot&1)?-1:1;
  return sign;
}

ll det(int grade){
  vector<int> p;
  for( int i=1;i<=grade;++i) p.push_back(i);
  ll result = 0, term = 1;
  
  for( int i = 0; i < grade; ++i ) term *= m[i][p[i]-1];
  result += term;
  
  while( next_permutation (p.begin(),p.end()) ){
    term = 1; 
    for( int i = 0; i < grade; ++i ) term *= m[i][p[i]-1];
    result += term*parity(p);;
  }
  return result;
}

void tartaglia(){
  
  for( int i = 0; i < 5; ++i ){
    m[0][i] = m[i][0] = 1;
    m[i][i] = 0;
  }
  
  m[1][2] = m[2][1] = AB*AB;
  m[1][3] = m[3][1] = AC*AC;
  m[1][4] = m[4][1] = AD*AD;
  m[2][3] = m[3][2] = BC*BC;
  m[2][4] = m[4][2] = BD*BD;
  m[3][4] = m[4][3] = CD*CD;
  
  printf("%.4lf\n",sqrt(det(5)/288.0));
}

int main(){
  int t;
  cin >> t;
  while( t-- ){
    cin >> AB >> AC >> AD >> BC >> BD >> CD;
    tartaglia();
  }
  return 0;
}