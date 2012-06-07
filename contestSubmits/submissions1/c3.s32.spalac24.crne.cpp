#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> par;

par f (int p) {
	if (p == 0) {
		return par(0,1);
	}
	else if (p == 1)
		return par(2,2);
	else if (p == 2)
		return par(4,2);
	else if (p&1) {
		par x = f(p-1);
		return par(x.first+x.second,x.second+1);
	}
	else {
		par x = f(p-1);
		return par (x.first+x.second,x.second);
	}
}

int main () {
	int x;
	cin>>x;
	cout<<f(x).first<<endl;
}
