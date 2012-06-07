#include <iostream>

using namespace std;

int main () {
	int comp [] = {1,1,2,2,2,8};
	int arr [8];
	for (int i = 0; i < 6; ++i) {
		cin>>arr[i];
	}
	for (int i = 0; i < 6; ++i) {
		cout<<comp[i]-arr[i];
		if (i < 5)
		cout<<" ";
	}
	cout<<endl;
}
