#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
ll t, r;
map<int, long long> dp;

ll solve( ll num ){
    if( num == 0 ) return dp[num];
    if( dp[num] == 0 ){
        r = max( num, solve(num/2) + solve(num/4) + solve(num/3) );
        dp[num] = r;
    }
    return dp[num];
}

int main(){
  dp.clear();
  while( scanf("%lli",&t) != EOF ) printf("%lli\n",solve(t));
  return 0;
}
