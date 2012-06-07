#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int size=0;
int c=0;
vector<pair<int,pii> > v(300000);
queue<pii> Q;

int f(int index,int x){
	c++;
	int value = v[index].first;
	int l = v[index].second.first;
	int r = v[index].second.second;
	if(value<x){
		if(l){
			Q.push(make_pair(l,x));
		}else{
			v[index].second.first = size;
			v[size].first = x;
			size++;
		}
	}else{
		if(r){
			Q.push(make_pair(r,x));
		}else{
			v[index].second.second = size;
			v[size].first = x;
			size++;
		}
	}
	return 0;
}


int main(){
	int n,x;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(size==0){
			v[size++].first = x;
		}else{
			Q.push(make_pair(0,x));
			while(!Q.empty()){
				pii p = Q.back(); Q.pop();
				f(p.first,p.second);
			}
		}
		printf("%d\n",c);
	}
	return 0;
}
