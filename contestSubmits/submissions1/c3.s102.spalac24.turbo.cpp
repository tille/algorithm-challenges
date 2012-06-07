#include <iostream>

using namespace std;

int main () {
	int n;
	cin>>n;
	int arr[n+4];
	int pos [n+4];
	for (int i = 0; i< n; ++i) {
		cin>>arr[i];
		pos[arr[i]]=i;
	}
	
	int curr = 0;
	int curr2 = n+1;
	for (int i = 1; i <= n; ++i) {
		if (i&1) {
			++curr;
			for (int j = curr+1; j <= n; ++j)
				if (pos[j]<pos[curr])
					++pos[j];
			 cout<<pos[curr]-curr+1<<endl;
		}
		else {
			--curr2;
			for (int j = curr2-1; j >= 1; --j)
				if (pos[j]>pos[curr2])
					--pos[j];
			cout<<curr2-pos[curr2]-1<<endl;
		}
	}
	
}
