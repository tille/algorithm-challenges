#include <iostream>
#include <cmath>

using namespace std;

const long double EMP = 1e-9;

unsigned long long dist (unsigned long long  x1, unsigned long long  y1, unsigned long long  x2, unsigned long long  y2) {
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

bool equals (unsigned long long  a, unsigned long long  b) {
	return a == b;
}

int main () {
	int n;
	int res = 0;
	cin>>n;
	unsigned long long  x[n+3];
	unsigned long long  y[n+3];
	for (int i = 0; i < n; ++i) {
		cin>>x[i]>>y[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			for (int k = j+1; k < n; ++k) {
				unsigned long long  a = dist(x[i],y[i],x[j],y[j]);
				unsigned long long b= dist(x[i],y[i],x[k],y[k]);
				unsigned long long c = dist(x[j],y[j],x[k],y[k]);
				//cout<<a<<" "<<b<<" "<<c<<endl;
				if (equals(a+b,c) || equals(a+c,b) || equals(b+c,a))
				++res;

			}
		}
	}
	cout<<res<<endl;
}
