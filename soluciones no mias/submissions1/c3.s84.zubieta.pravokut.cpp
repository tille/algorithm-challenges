#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;
int main(){
	double z[1502][2];
	double d1,d2,d3;
	int vertices;
	int cont;
	while(cin>>vertices){
		cont=0;
		for(int m=0;m<vertices;++m){
			cin>>z[m][0]>>z[m][1];
		}
		for(int a=0;a<vertices-2;++a){
			for(int b=a+1;b<vertices-1;++b){
				for(int c=b+1;c<vertices;++c){
					d1 = pow(z[a][0]-z[b][0],2)+pow(z[a][1]-z[b][1],2);
					d2 = pow(z[b][0]-z[c][0],2)+pow(z[b][1]-z[c][1],2);
					d3 = pow(z[c][0]-z[a][0],2)+pow(z[c][1]-z[a][1],2);
					if(d1+d2==d3 || d2+d3==d1 || d3+d1==d2){
						cont++;
					}
				}
			}
		}
		cout << cont << endl;
	}
}