#include<iostream>

using namespace std;

int dp[605][605], h[605], w[605], tw, th, t, n;

void trivial_cases(){
    for( int i = 0; i <= th; ++i ) for( int j = 0; j <= tw; ++j ) dp[i][j] = i*j;
    for( int i = 0; i < n; ++i )  dp[h[i]][w[i]] = 0;
}

int main(){
    scanf("%d",&t);
    while( t-- ){
        scanf("%d%d",&tw,&th);
        scanf("%d",&n);
        for( int i = 0; i<n; ++i ) scanf("%d%d",&w[i],&h[i]);
        trivial_cases();

        for( int i = 1; i <= th; ++i ){
            for( int j = 1;  j<= tw; ++j ){
                for( int d = 1; d <= j; ++d ){
                    dp[i][j] = min( dp[i][j],dp[i][j-d] + dp[i][d] );
                }
                for( int d = 1; d <= i; ++d ){
                    dp[i][j] = min( dp[i][j],dp[i-d][j] + dp[d][j] );
                }
            }
        }
        cout << dp[th][tw] << endl;


    }
    return 0;
}
