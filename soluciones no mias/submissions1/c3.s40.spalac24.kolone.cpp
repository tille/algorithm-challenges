#include <iostream>
#include <cmath>

using namespace std;

int main () {
	 int n1,n2;
	 string s1,s2;
	 int t;
	 cin>>n1>>n2>>s1>>s2>>t;
	 int count = s1.size();
	 for (int i = 0; i < (int)s1.size()-t; ++i) {
		 cout<<s1[s1.size()-i-1];
		 count = s1.size()-i-1;
	 }
	 
	 //cout<<"|";
	 
	 int i ;
	 int count2 = 0;
	 for (i = 0; i < 2*t and count > 0 and count2<(int)s2.size(); ++i) {
		 if ((i&1))
			cout<<s1[--count];
		 else 
			cout<<s2[count2++];
	 }
	 
	 //cout<<"|";
	 for (int i = count; i > 0; --i) {
		 cout<<s1[i];
	 }
	 
	 for (int i = count2; i < (int)s2.size();++i)
		cout<<s2[i];
	cout<<endl;
}
