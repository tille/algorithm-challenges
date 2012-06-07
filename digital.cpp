using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

typedef long long ll;

int visited[10000006];

ll pot( ll number, ll exp, ll c ){
    if( number == 0 && exp == 0 ) return 1;
    else if( number == 0 ) return 0;
    else if( number == 1 ) return 1;
    else if( exp == 0 ) return 1;
    else{
        ll result = number%c;
        for( int i = 1; i < exp; ++i ){
            result *= (number%c);
        }
        return (result%c);
    }
}

ll r[16];
set<ll> s;

long long compute(long long a, long long b, int n, long long c) {
  long long ans = a % c;
  for(int k = 0; k < n; ++k)
    ans = (ans * b) % c;
  return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    ll n,m;
    while( cin >> n >> m ){
        if( n == 0 and m == 0) break;
        int cant;
        cin >> cant;
        vector<ll> r(cant+1);
        s.clear();

        for( int i = 0; i <= cant; ++i ) cin >> r[i];

        if( cant == 0 ) puts("1");
        else{
            ll c = n+1;
            for( ll i = 0; i <= m; ++i ){
                ll result = r[0]%c;
                for( ll j = 1; j <= cant; ++j ){
                    result = (result +  compute(r[j],i,j,c) )%c;
                }
                s.insert(result);
            }
            cout << s.size() << endl;
        }


    }
    return 0;
}
