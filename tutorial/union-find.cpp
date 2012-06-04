#include <iostream>

using namespace std;

void init(int n){
	for(int i = 0; i < n; ++i) p[i] = i;
}

int find(int u){
	return p[u]==u?u:p[u]=find(p[u]);
}

void link(int u, int v){
	int a = find(u);
	int b = find(v);
	if(a!=b) p[a] = b;
}

int main(){
	return 0;
}