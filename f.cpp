#include <iostream>
#include <vector>

using namespace std;

// f(i,c) = max ( f(i+1,c), f(flecha[i],c-1)+v[i] )
// m^n = (m^(n-1))*m si k es inpar -> ((m^(k/2))^2)*m
// m^n = (m^(n/2))^2 si n es par

vector<int> r[100];
int v[100];
int dp[100][100];

void init(){
	r[0].push_back(1);
	r[0].push_back(4);
	r[1].push_back(2);
	r[1].push_back(3);
}

int dfs(int n){
	if(!r[n].size()) return 1;
	else{
		int result = 0;
		
		for( unsigned int i = 0; i < r[n].size(); ++i ){
			result += v[r[n][i]] = dfs(r[n][i]);
		}
		return ++result;
	}
}

void f(int n){
	for( int i = n-1; i > -1; --i ){
		for( int j = 1; j <= n; ++j ){
			dp[i][j] = max( dp[i+1][j], dp[i+v[i]][j-1]+(i+1) );
		}
	}
}

int main(){
	/*init();
	v[0] = dfs(0);
	f(5);
	for( int i = 0; i <= 5; ++i ){
		for( int j = 0; j <= 5; ++j ){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}


