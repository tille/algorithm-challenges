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

int a[105], n;

bool check(int m) {
    for (int i = 0; i < n; ++i) {
        if (a[i] % m != 0) return false;
    }
    return true;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    int smallest = a[0];
    for (int i = 0; i < n; ++i) {
        a[i] -= smallest;
    }
    
    set<int> ans;
    for (int i = 0; i < n; ++i) {
        int A = a[i];
        for (int d = 1; 1LL * d * d <= A; ++d) {
            if (A % d == 0) {
                if (check(d)) ans.insert(d);
                if (check(A / d)) ans.insert(A / d);
            }
        }
    }
    ans.erase(1);
    foreach(p, ans) printf("%d ", *p);
    puts("");
    return 0;
}