#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main () {
	int arr [3];
	cin>>arr[0]>>arr[1]>>arr[2];
	sort(arr,arr+3);
	string s;
	cin>>s;
	for (int i = 0; i < 3; ++i) {
		if (s[i]=='A')
			cout<<arr[0];
		else if (s[i]=='B')
			cout<<arr[1];
		else cout<<arr[2];
		
			cout<<" ";
	}
}
