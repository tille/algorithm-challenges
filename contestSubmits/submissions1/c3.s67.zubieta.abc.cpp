#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<map>

using namespace std;
int main(){
	int x[3];
	string abece;
	while(cin>>x[0]>>x[1]>>x[2]){
		cin>>abece;
		map<char,int> mapa;
		sort(x,x+3);
		mapa['A']=x[0];
		mapa['B']=x[1];
		mapa['C']=x[2];
		for(int z=0;z<abece.length();++z){
			cout<< mapa[abece[z]] << " ";
		}
		cout << endl;
	}
}