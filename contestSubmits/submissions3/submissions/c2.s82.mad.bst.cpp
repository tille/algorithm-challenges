#include <cstdio>
#include <map>

using namespace std;


int main(){
	int n,x;
	long long int c=0;
	scanf("%d",&n);
	map<int,long long int> m;
	for(int i=0;i<n;i++){
		scanf("%d",&x);

		if(m.size()==0){
			m[x] = 0;
			m[n+1] = 0;
			m[0] = 0;
		}else{
			map<int,long long int> ::iterator low = m.lower_bound(x); low--;
			map<int,long long int> ::iterator up = m.upper_bound(x);

			long long int value = 0;

			if((*low).first<x)
				value = max(value,m[(*low).first]);

			if((*up).first>x)
				value = max(value,m[(*up).first]);

			m[x] = value+1;
		}
		c+=m[x];
		//printf("m[x]:%d\n",m[x]);
		printf("%lld\n",c);
	}
	return 0;
}
