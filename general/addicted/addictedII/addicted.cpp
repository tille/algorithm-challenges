#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


template <int limS>
class PiggiesSet {
	public:

	int S,E,N;
	int counts[limS+1];

	PiggiesSet() : N(0) {
	}
	
	void trunc() {
		if (N==0) return;
		while (counts[S]==0) S++;
		while (counts[E]==0) E--;
	}

	void expandTo(int a) {
		if (N==0) {
			S=E = a;
			counts[a] = 0;
			return;
		}

		if (a<S) {
			memset(&counts[a], 0, (S-a)*sizeof(int));
			S = a;
		}

		if (E<a) {
			memset(&counts[E+1], 0, (a-E)*sizeof(int));
			E = a;
		}
	}

	void rem(int a, int c=1) {
		counts[a] -= c;
		N -= c;
		trunc();
	}

	void add(int a, int c=1) {
		expandTo(a);
		counts[a] += c;
		N += c;
	}

	int getMin(int c=1) {
		int r = S;
		rem(S, c);
		return r;
	}

	int getMax(int c=1) {
		int r = E;
		rem(E, c);
		return r;
	}
};


/*class Piggy {
	public:
	int idx;
	int val;

	Piggy() {
	}

	Piggy(int _idx) :
		idx(_idx), val(0) {
	}

	void add() {
		val++;
	}

	bool operator< (const Piggy& oth) const {
		return val > oth.val;
	}
};*/


#define MAX_N (100*1024)
#define MAX_S (100*1024)


int main() {
  int t;
  //freopen("addictedII_out.txt","w",stdout);
  scanf("%d",&t);
  while( t-- ){
  	int N; scanf("%d", &N);
  	PiggiesSet<MAX_S> *ps = new PiggiesSet<MAX_S>;
  	ps->add(0, N);

  	char ch; while((ch=getchar()) <= ' ');
  	while (ch>' ') {
  		int a = ps->getMin();
  		int b = ps->getMin();
  		(ch=='1') ? a++ : b++;

  		ps->add(a);
  		ps->add(b);

  		ch = getchar();
  	}

  	int a = ps->getMin();
  	int b = ps->getMin();
  	printf("%d %d\n", a,b);

  	delete ps;
  }
  return 0;
}


