#include <iostream>

using namespace std;

typedef unsigned long long ll;

ll f (ll x) {
	ll nvertex = x-3;
	ll res = 0;
	ll prev = nvertex;
	ll i;
	for (i = 1; i <= nvertex/2; ++i) {
		res += prev*i;
		prev--;
	}
	res *= 2;
	if (nvertex&1) {
		res += prev*i;
	}
	return res;
}

int main () {
	ll x;
	cin>>x;
	cout<<f(x)*(x)/4<<endl;
}
