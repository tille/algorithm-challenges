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

const int MAXR = 30005, MAXC = 35;

int R, C;
char mat[MAXR][MAXC];

// void update(int i, int j) {
//     
//     if (mat[i][j] != '.') {
//         next[i][j] = make_pair(i - 1, j);
//         return;
//     }
//     
//     if (mat[i + 1][j] == '.') {
//         next[i][j] = make_pair(i + 1, j);
//         return;
//     }
//     
//     if (mat[i][j - 1] == '.' and mat[i + 1][j - 1] == '.') { //drop left
//         next[i][j] = make_pair(i, j - 1);
//         return;
//     }
//     
//     if (mat[i][j + 1] == '.' and mat[i + 1][j + 1] == '.' ) {
//         next[i][j] = make_pair(i, j + 1);
//         return;
//     }
//     next[i][j] = make_pair(i, j);
//     return;
// }

set<int> things[MAXC];

void drop(int i, int j) {
    set<int>::iterator where = things[j].upper_bound( i );
    int next = (*where) - 1;
    assert( mat[next][j] == '.' );
    assert( mat[next + 1][j] != '.' );
    if (mat[next + 1][j] == 'X') {
        mat[next][j] = 'O';
        things[j].insert(next);
        return;
    }
    assert(mat[next + 1][j] == 'O');
    if (mat[next][j - 1] == '.' and mat[next + 1][j - 1] == '.') {
        drop(next, j - 1);
        return;
    }
    
    if (mat[next][j + 1] == '.' and mat[next + 1][j + 1] == '.') {
        drop(next, j + 1);
        return;
    }
    
    mat[next][j] = 'O';
    things[j].insert(next);
    return;
}


int main(){
    memset(mat, 'X', sizeof mat);
    scanf("%d %d ", &R, &C);
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            scanf("%c ", &mat[i][j]);
        }
    }
    
    // for (int i = 1; i <= R; ++i) {
    //     for (int j = 1; j <= C; ++j) {
    //         printf("%c", mat[i][j]);
    //     }
    //     puts("");
    // }
    
    for (int j = 1; j <= C; ++j) {
        for (int i = R+1; i >= 0; --i) {
            if (mat[i][j] != '.') things[j].insert(i);
        }
    }

    
    int times; scanf("%d", &times);
    while (times--) {
        int c; scanf("%d", &c);
        drop(1, c);

    }
    
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            printf("%c", mat[i][j]);
        }
        puts("");
    }
    
    return 0;
}