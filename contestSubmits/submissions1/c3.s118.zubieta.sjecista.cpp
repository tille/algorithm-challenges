#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

unsigned long long itsAFact(int x){
    if(x<=1)
		return 1;
    else
		return x * itsAFact(x-1);
}


int main(){
	int x;
	while(cin>>x){
		cout << ((x-3)*(x-2)*(x-1)*x)/itsAFact(4)<<endl;
	}
}