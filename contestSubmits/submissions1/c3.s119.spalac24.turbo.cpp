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
	
	int deltapos [n+4];
	
	for (int i = 1; i <= n; ++i) {
		deltapos[i]=0;
		if (i > n/2+(n&1)) {
			for (int j = i+1; j <= n; ++j) {
				if (pos[j]<pos[i]){
					--deltapos[i];
					//cout<<"++por "<<j<<" "<<i<<" se corre a la <-\n";
				}
			}
			for (int j = 1; j <= n-i+1; ++j) {
				if (pos[j]>pos[i])
					++deltapos[i];
			//		cout<<"--por "<<j<<" "<<i<<" se corre a la ->\n";
			}
		}
		else{
			if (i == n/2+(n&1)) {
				for (int j = 1; j < i; ++j)
				if(pos[j]>pos[i]){
				++deltapos[i];
				//cout<<"\\\\por "<<j<<" "<<i<<" se corre a la ->\n";
			}
				for (int j = i+1; j <= n; ++j)
				if (pos[j]<pos[i]){
				--deltapos[i];
				//cout<<"//por "<<j<<" "<<i<<" se corre a la <-\n";
			}
				continue;
			}
			for (int j = 1; j <= i-1; ++j) {
				if (pos[j] > pos[i]){
					++deltapos[i];
				//	cout<<"\\\\por "<<j<<" "<<i<<" se corre a la ->\n";
				}
			}
			for (int j = n-i/2+(n&1); j <= n ; ++j) {
				if (pos[j]<pos[i]){
					--deltapos[i];
			//		cout<<"//por "<<j<<" "<<i<<" se corre a la <-\n";
				}
			}
		}
	}
	int curr = 0, curr2 = n+1;
	for (int i = 1; i <= n; ++i) {
		if (i&1) {
			++curr;
			 cout<<pos[curr]+deltapos[curr]-curr+1<<endl;
		}
		else {
			--curr2;
			cout<<curr2-pos[curr2]-deltapos[curr2]-1<<endl;
		}
	}
	
}
