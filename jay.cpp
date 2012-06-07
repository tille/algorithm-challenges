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
typedef pair<int,int> p;

int r[106];
vector<p> t;

int main(){
    int n,a,b,acum;
    while( cin >> n && n ){
        t.clear();
        acum = 0;
        for( int i = 0; i < n; ++i ){
            cin >> a >> b;
            r[i] = acum;
            acum += b;
            t.push_back( p(a,i) );
        }

        sort( t.begin(), t.end() );
        int tot = 0;

        for( int i = t.size()-1; i > -1; --i ){
            int temp = t[i].second;
            int temp2 = t[i].first;

            if( r[temp] > 0 ){
                for( int j = temp+1; j <= n; ++j ) r[j]--;
                for( int j = temp-1; j > -1; --j ){
                    if( r[j] == r[temp] ) r[j]--;
                    else break;
                }
                r[temp]--;
                temp2/=2;
            }
            tot += temp2;

        }

        cout << tot << endl;
    }
    return 0;
}
