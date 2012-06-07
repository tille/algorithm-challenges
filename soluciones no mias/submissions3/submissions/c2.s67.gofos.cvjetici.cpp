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

const int MAXN = 200010;
const int SHIFT = 10;

int tree[MAXN];

void add(int where, long long what) {
    for (where += SHIFT; where < MAXN; where += where & -where) {
        tree[where] += what;
    }
}

long long query(int where) {
    long long ans = 0;
    for (where += SHIFT; where > 0; where -= where & -where) {
        ans += tree[where];
    }
    return ans;
}

void increase(int i, int j, long long by) { // [i, j]
    // printf("increase(%d, %d, by %lld)\n", i, j, by);
    if (i > j) return;
    add(i,      by);
    add(j + 1, -by);
}

long long at(int i) {
    return query(i);// - query(i - 1);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        long long left = at(u), right = at(v);
        printf("%lld\n", left + right);
        increase(u, u, -left);
        increase(v, v, -right);
        assert(at(left) == 0);
        assert(at(right) == 0);
        
        increase(u + 1, v - 1, +1);
    }
    return 0;
}