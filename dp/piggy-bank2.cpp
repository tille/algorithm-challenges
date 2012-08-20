#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

template <class T> T Min(T a, T b){ return a < b ? a : b; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)

int t, E, F, maxCoins, peso;
int b[504][2], dp[10004];

void solve(){
    for ( int i = 1; i<=peso ; ++i ) {
        dp[i] = 1<<30;
        for ( int j = 0; j < maxCoins; ++j ) {
            if( b[j][1] <= i ) dp[i] = min(dp[i],dp[ i-b[j][1] ] + b[j][0]);
        }
    }
}

int main(){
  scanf("%d",&t);
  dp[0] = 0;
  while( t-- ){
    scanf("%d%d%d",&E,&F,&maxCoins);
    peso = F-E;
    for ( int i = 0; i< maxCoins; ++i ){ scanf("%d%d",&b[i][0],&b[i][1]); }
    solve();
    if(dp[peso] != 1<<30 ) printf("The minimum amount of money in the piggy-bank is %d.\n", dp[peso]);
    else puts("This is impossible.");
  }
  return 0;
}
