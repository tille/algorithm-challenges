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

bool forward[256];

int main(){
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < n; ++i) {
        forward[a[i] - 'A'] = true;
    }
    
    vector<int> v;
    for (int i = n - 1; i >= 0; i--) {
        v.push_back( a[i] - 'A' );
    }
    for (int i = 0; i < m; ++i) {
        v.push_back( b[i] - 'A' );
    }
    
    int T;
    cin >> T;
        
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j + 1 < v.size(); ++j) {
            if (forward[ v[j] ] && !forward[ v[j + 1] ]) {
                swap(v[j], v[j + 1]);
                j++;
            }
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << char(v[i] + 'A');
    }
    cout << endl;
    return 0;
}