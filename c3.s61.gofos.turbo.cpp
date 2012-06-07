// Andrés Mejía
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
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

////////////// Prewritten code follows. Look down for solution. ////////////////
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 100010;
int a[MAXN];
int rank[MAXN];
int tree[MAXN];

int add(int where, int what) {
    for (where++; where < MAXN; where += where & -where) {
        tree[where] += what;
    }
    return 0;
}

int query(int where) {
    int ans = 0;
    for (where++; where > 0; where -= where & -where) {
        ans += tree[where];
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        rank[ a[i] ] = i + 1;
        add(i + 1, 1);
    }
    
    int nextSmall = 1, nextBig = n;
    for (int k = 0; k <= (n / 2); ++k) {
        int pos;
        
        pos = rank[ nextSmall ];
        int ans = query(pos - 1);
        add(pos, -1);
        printf("%d\n", ans);
        
        if (nextBig != nextSmall) {
            pos = rank[ nextBig ];
            int ans = query(n + 1) - query(pos);
            printf("%d\n", ans);
            add(pos, -1);
        }        
        nextSmall++;
        nextBig--;
    }
    return 0;
}