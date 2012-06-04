#include <iostream>

using namespace std;

const int h = 10;
const int MAXN = 4*h;  
int tree[MAXN];
int a[h];

// l y r los rangos del intervalo
// p y q los rangos de la pregunta
int query(int u, int l, int r, int p, int q){
	// todo adentro
	if( q<l or p>r ) return -(1<<30);
	// todo afuera
	if( p<=l && r<=q ) return tree[u];
	int m = (l+r)/2;
	int a = query(2*u+1,l,m,p,q);
	int b = query(2*u+2,m+1,r,p,q);
	return max(a,b);
}

void update(int u, int l, int r, int at, int what ){
	if( at < l or r < at ) return;
	if( at == l && at == r ){
		tree[u] = what;
		return;
	}
	int m = (l+r)/2;
	update(2*u+1,l,m,at,what);
	update(2*u+2,m+1,r,at,what);
	tree[u] = max(tree[2*u+1], tree[2*u+2]);
}

void nueva(int u,int l,int r){
	if( l == r ){
		tree[u] = a[l];
		return;
	}
	int m = (l+r)/2;
	nueva(2*u+1,l,m);
	nueva(2*u+2,m+1,r);
	tree[u] = max(tree[2*u+1], tree[2*u+2]);
}

int main(){
	for( int i = 0; i < 10; ++i ) a[i] = i;
	nueva(0,0,9);
	/*update(0,0,9,0,a[0]);
	update(0,0,9,1,a[1]);
	update(0,0,9,2,a[2]);
	update(0,0,9,3,a[3]);
	update(0,0,9,4,a[4]);*/
	//for( int j = 0; j < 10; ++j ) cout << a[j] << endl;
		cout << query(0,0,9,0,4) << endl;
	return 0;
}