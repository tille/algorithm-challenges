#include <iostream>
#include <string>

using namespace std;

#define MAXN 84

int dp[MAXN][MAXN];
vector<int> words[MAXN][MAXN];

void calc(string a, string b){
	for( int i = 0; i < a.size(); ++i ){
		for( int j = 0; j < b.size(); ++j ){
			int temp = (a[i] == b[j])?dp[i][j]+1:0;
			dp[i+1][j+1] = max(temp, max(dp[i+1][j], dp[i][j+1]));
		}
	}
}

aac
aab

aca
acc

abb
aba

void debug(string a, string b){
	cout << "   " << b << endl;
	for( int i = 0; i <= a.size(); ++i ){
		if(i) cout << a[i-1] << " ";
		if(!i) cout << "  ";
		for( int j = 0; j <= b.size(); ++j ){
			cout << dp[i][j] << "";
		}
		cout << endl;
	}
}

int main(){
	string a,b;
	int t;
	cin >> t;
	for( int i = 0; i < MAXN; ++i )  dp[i][0] = dp[0][i] = 0;
	while(t--){
		cin >> a >> b;
		calc(a,b);
		debug(a, b);
	}
	return 0;
}