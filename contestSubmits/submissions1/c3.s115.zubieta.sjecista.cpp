#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

long itsAFact(long x){
    if(x<=1)
		return 1;
    else
		return x * itsAFact(x-1);
}


int main(){
	int x;
	while(cin>>x){
		cout << itsAFact(x)/(itsAFact(4)*itsAFact(x-4))<<endl;
	}
}



