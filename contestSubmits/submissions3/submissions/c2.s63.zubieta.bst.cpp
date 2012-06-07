#include <iostream>
#include <numeric>
#include <fstream>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

int C;
struct nodo{
	int valor;
	struct nodo *izq;
	struct nodo *der;
};

void inst(nodo **bst, nodo *nod){
	if(!(*bst)){
		*bst = nod;
	}
	else{
		C++;
		if(nod->valor<(*bst)->valor){
			inst(&(*bst)->izq,nod);
		}
		else{
			inst(&(*bst)->der,nod);
		}
	}
}

int main(){
	int n;
	cin >> n;
	int nums[n];
	C=0;
	for(int i=0; i<n; ++i){
		cin >> nums[i];
	}
	nodo *tree;
	nodo *nod;
	nod = (nodo *)malloc(sizeof(nodo));
	nod->valor = nums[0];
	nod->izq = nod->der = NULL;
	tree = nod;
	for(int j=1; j<n; ++j){
		nod = (nodo *)malloc(sizeof(nodo));
		nod->valor = nums[j];
		nod->izq = nod->der = NULL;
		inst(&tree,nod);
		cout << C << endl;
	}
}