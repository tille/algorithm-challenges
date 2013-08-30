using namespace std;
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <stdio.h>

#define MAXN 102
#define MAXM 100002
#define inf 1<<30

double dp[MAXN][MAXM];
vector<int> list;
vector<int> products;
vector<double> prices;  

double dp_calc(int n, int m){
  for( int i = 1; i <= n; ++i ){
    for( int j = 1; j <= m; ++j ){
      if( list[i-1] == products[j-1] ){
        dp[i][j] = (dp[i-1][j-1] == double(inf))?inf:min( dp[i][j-1], dp[i-1][j-1]+prices[j-1] );
      }else dp[i][j] = dp[i][j-1];
    }
  }
  
  return dp[n][m];
}

int main(){
  int n, m, num_list, product;
  double price;
  for( int i = 0;  i < MAXM; ++i ) dp[0][i] = 0;
  for( int i = 0;  i < MAXN; ++i ) dp[i][0] = inf;

  while( cin >> n >> m && n+m ){    
    list.clear();
    products.clear();
    prices.clear();

    for( int i = 0; i < n; ++i ){
      cin >> num_list;
      list.push_back(num_list);
    }
  
    for( int i = 0; i < m; ++i ){
      cin >> product >> price;
      products.push_back(product);
      prices.push_back(price);
    }

    double ans = dp_calc(n,m);
    if( int(ans) == inf ) cout << "Impossible" << endl;
    else printf("%.2f\n",ans);
    
    // for( int i = 1; i <= n; ++i ){
    //   for( int j = 1; j <= m; ++j ){
    //     if(dp[i][j] == 1073741824) cout << "oo\t"; 
    //     else cout << dp[i][j] << "\t";
    //   }
    //   cout << endl;
    // }    
    // cout << endl;
  }

  return 0;
}