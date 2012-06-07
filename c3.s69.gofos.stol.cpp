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

const int MAXN = 405;
bool mat[MAXN][MAXN];
int row[MAXN];

int main(){
    int R, C;
    scanf("%d %d ", &R, &C);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char c; scanf("%c ", &c);
            mat[i][j] = (c == '.');
            
            //printf("%d ", mat[i][j]);
        }
        //puts("");
    }
    int ans = -1;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (mat[i][j]) {
                row[j]++;
            } else {
                row[j] = 0;
            }
        }
        // printf("row when i = %d\n", i);
        // For(j, 0, C) printf("%d ", row[j]); puts("");
        
        for (int j = 0; j < C; ++j) {
            int small = row[j];
            for (int k = j; small > 0 and k < C; k++) {
                small = min(small, row[k]);
                
                int option = 2 * (k - j + 1) + 2 * small ;
                ans = max(ans,  option );
                
                // printf("Option from i = %d, j = %d, k = %d:\n", i, j, k);
                // For(p, j, k + 1) printf("%d ", row[i]); puts("");
                // printf("size = %d\n", option);
                
            }
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}