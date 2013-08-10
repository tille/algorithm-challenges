#include <iostream>

using namespace std;

typedef unsigned long long ll;
#define MAXN 10

ll t,n,k;
ll b[MAXN+2], c[MAXN+2], a[MAXN+2];

int main(){
	cin >> t;
	while(t--){
		cin >> k;
		for( ll i = 0; i < (k*2); ++i ){
			if(i<k) cin >> b[i];
			else cin >> c[i-k];
		}
		cin >> n;
		
		
	}
	return 0;
}