#include <iostream>
#include <numeric>
#include <fstream>
#include <climits>
#include <cstdlib>
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
#include <cassert>
#include <sstream>
#include <iterator>
#include <algorithm>
#define ull unsigned long long
#define EPS 1e-9
using namespace std;

int main(){	
	int pago;
	int A;
	int B;
	int C;
	int a,b,c,d,e,f;
	int hora;
	while(cin >> A >> B >> C){
		cin >> a >> b;
		cin >> c >> d;
		cin >> e >> f;
		hora=0;
		pago=0;
		b--;
		d--;
		f--;
		while(hora<=max(max(b,d),f)){
			if(a<=hora && hora<=b && c<=hora && hora<=d && e<=hora && hora<=f){
				pago += C*3;
			}
			if(((a<=hora&&hora<=b)&&(c<=hora&&hora<=d)&&(e>hora||hora>f))||((a<=hora&&hora<=b)&&(e<=hora&&hora<=f)&&(c>hora||hora>d))||((e<=hora&&hora<=f)&&(c<=hora&&hora<=d)&&(a>hora||hora>b))){
				pago += B*2;
			}
			if(((a<=hora&&hora<=b)&&(c>hora||hora>d)&&(e>hora||hora>f))||((a>hora||hora>b)&&(e<=hora&&hora<=f)&&(c>hora||hora>d))||((e>hora||hora>f)&&(c<=hora&&hora<=d)&&(a>hora||hora>b))){
				pago += A;
			}
			hora++;
		}
		cout << pago << endl;
	}
}	

