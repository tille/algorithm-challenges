#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main () {
	 int n1,n2;
	 string s1,s2;
	 int t;
	 cin>>n1>>n2>>s1>>s2>>t;
	 /*int count = s1.size();
	 if (t < (int)s1.size()){
		t = min(t,min((int)s1.size(),(int)s2.size()));
		 for (int i = 0; i < (int)s1.size()-t; ++i) {
			 cout<<s1[s1.size()-i-1];
			 count = s1.size()-i-1;
		 }
		 
		//cout<<"|";
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
	}*/
	
	string res;
	for (int i =1; i <= n1; ++i)
	res += s1[n1-i];
	res += s2;
	int c1 = s1.size()-1;
	int c2 = s1.size();
	if (t > 0) {
		char aux = res[c1];
		res[c1]=res[c2];
		res[c2]=aux;
		c2--;
		c1++;
		t--;
	}
	int A = 0;
	int B = res.size()-1;
	while(t--) {
		
			//cout<<res<<endl;
		//cout<<"t = "<<t<<endl;
		if (c2 <= A){
		A+=2;
		c2 = A;;
		}
		int i = c2;
		//cout<<"c2 = "<<c2<<endl;
		//cout<<"c1 = "<<c1<<endl;
		for (; i < min(c1+2,B+1); i += 2) {
			//cout<<"i = "<<i<<endl;
			char aux = res[i];
			res[i]=res[i-1];
			res[i-1]=aux;
		}
		--c2;
		++c1;
		if (c1 >= B){
			--B;
			c1 = B;
		}
		if (A > B) {
			char aux = res[c1];
			res[c1]=res[c2];
			res[c2]=aux;
			if (!res.substr(0,n2).compare(s2))
				break;
		}
		
	//cout<<res<<endl;
	}
	cout<<res<<endl;
	}
