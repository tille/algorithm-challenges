#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int s,n;
int dp[3000][3000], w[3000], v[3000];

int main(){
    for( int i = 0; i <=3000 ; ++i ) dp[i][0] = dp[0][i] = 0;

    while( cin >> s >> n ){
        for( int i = 1; i<=n; ++i ) cin >> w[i] >> v[i];

        // DP in Two Dimensions
        for( int i = 1; i <=n ; ++i ){
            for( int j = 1; j <=s ; ++j ){
                if( w[i] > j ) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max( dp[i-1][j], dp[i-1][j-w[i]] + v[i] );
            }
        }

        cout << dp[n][s] << endl;
    }
    return 0;
}
