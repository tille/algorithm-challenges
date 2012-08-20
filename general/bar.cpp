#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int v[1004];
int dp[1004][1004];

void f(int n, int p){
  for( int i = p-1; i > -1; --i ){
    for( int j = 1; j <= n; ++j ){
      if( j-v[i] >= 0 ){
        dp[i][j] = max( dp[i+1][j], dp[i+1][j-v[i]]+v[i] );
      }else{
        dp[i][j] = dp[i+1][j];
      }
    }
  }
}

int main(){
  int t, n, p;
  cin >> t;
  while( t-- ){
    for( int i = 0; i < 1003; ++i ) for( int j = 0; j<1003; ++j ) dp[i][j] = 0;
    cin >> n;
    cin >> p;
    for( int i=0; i<p; ++i ) cin >> v[i];

    f(n,p);
    if(dp[0][n] == n) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}