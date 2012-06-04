#include <iostream>

using namespace std;

long long fib[82];

void init(){
	fib[0]=0; fib[1]=1;
	for( int i = 2; i < 82; ++i ) fib[i] = fib[i-1] + fib[i-2];
}

int main(){
	init();
	int n;
	while( cin >> n && n ){
		cout << fib[n+1] << endl;
	}
	return 0;
}