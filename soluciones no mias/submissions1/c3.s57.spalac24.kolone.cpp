#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main () {
	 int n1,n2;
	 string s1,s2;
	 int t;
	 cin>>n1>>n2>>s1>>s2>>t;
	 int count = s1.size();
	 if (t < (int)s1.size()){
		t = min(t,min((int)s1.size(),(int)s2.size()));
		 for (int i = 0; i < (int)s1.size()-t; ++i) {
			 cout<<s1[s1.size()-i-1];
			 count = s1.size()-i-1;
		 }
		 
		// cout<<"|";
		 t = min(t,min((int)s1.size(),(int)s2.size()));
		 int i ;
		 int count2 = 0;
		 for (i = 0; i < 2*t and count > 0 and count2<(int)s2.size(); ++i) {
			 if ((i&1))
				cout<<s1[--count];
			 else 
				cout<<s2[count2++];
		 }
		 
		// cout<<"|";
		 for (int i = count; i > 0; --i) {
			 cout<<s1[i];
		 }
		 
		 for (int i = count2; i < (int)s2.size();++i)
			cout<<s2[i];
		cout<<endl;
	}
	else {
		 count = -1;
		 //int k = s2.size()-min(t,min((int)s1.size(),(int)s2.size()));
		 int k = t - s1.size();
		 k = min(k,(int)s2.size());
		 for (int i = 0; i < k; ++i) {
		 cout<<s2[i];
		 count = i;
		}
		// cout<<"|";
		 int i ;
		 int count2 = s1.size();
		 for (i = 0; i < 2*t and count <(int) s1.size() and count2>0; ++i) {
			 if (!(i&1))
				cout<<s2[++count];
			 else 
				cout<<s1[--count2];
		 }
		 //cout<<"|";
		 for (int i = count+1; i < (int)s2.size();++i)
			cout<<s2[i];
		 for (int i = count2-1; i >= 0; --i) {
			 cout<<s1[i];
		 }
	 
	cout<<endl;
	}
	}
