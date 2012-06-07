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

enum { Up, Right, Down, Left };

int di[] = { -1, +0, +1, +0 };
int dj[] = { +0, +1, +0, -1 };

int nextDirection(int cur, char next) {
    if (cur == Right) {
        if (next == '-') return Right;
        if (next == '+') return Right;
        if (next == '3') return Up;
        if (next == '4') return Down;
        return -1;
    }
    
    if (cur == Left) {
        if (next == '-') return Left;
        if (next == '+') return Left;
        if (next == '1') return Down;
        if (next == '2') return Up;
        return -1;
    }
    
    if (cur == Up) {
        if (next == '|') return Up;
        if (next == '+') return Up;
        if (next == '1') return Right;
        if (next == '4') return Left;
        return -1;
    }
    
    assert(cur == Down);
    if (cur == Down) {
        if (next == '|') return Down;
        if (next == '+') return Down;
        if (next == '2') return Right;
        if (next == '3') return Left;
        return -1;
    }
    assert(false);
}

const int MAXN = 30;
char mat[MAXN][MAXN];
int rows, cols;

bool outside(int r, int c) {
    if (r < 0 or r >= rows) return true;
    if (c < 0 or c >= cols) return true;
    return false;
}

int mustSeeNormal, mustSeeCrosses;

bool reach(int i, int j, int dir, int seenNormal, int seenCrosses) {
    // printf("reach(%d, %d, dir=%d)\n", i, j, dir);
    
    if ( outside(i, j) ) {
        return false;
    }
    
    if (mat[i][j] == 'Z') {
        if (mustSeeNormal == seenNormal and mustSeeCrosses == seenCrosses) return true;
        return false;
    }
    
    int nextDir = nextDirection(dir, mat[i][j]);
    if (nextDir == -1) return false;
    
    assert(mat[i][j] != 'Z' and mat[i][j] != 'M');
    seenCrosses += (mat[i][j] == '+');
    seenNormal += (mat[i][j] != '.' and mat[i][j] != '+');
    
    
    return reach( i + di[nextDir], j + dj[nextDir], nextDir, seenNormal, seenCrosses );
}

bool check(pair<int, int> start) {
    // printf("Called check\n");
    //     For(i, 0, rows){For(j, 0, cols)printf("%c", mat[i][j]);printf("\n");}printf("\n");
        
    int si = start.first, sj = start.second;
    for (int k = 0; k < 4; ++k) {
        int ni = si + di[k];
        int nj = sj + dj[k];
        if (outside(ni, nj) ) continue;
        if (mat[ni][nj] != '.') return reach(ni, nj, k, 0, 0);
    }
    assert(false);
}

int main(){
    scanf("%d %d ", &rows, &cols);

    pair<int, int> start(-1, -1);
    int crosses = 0;
    int normal = 0;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%c ", &mat[i][j]);
            if (mat[i][j] == 'M') start = make_pair(i, j);
            
            crosses += (mat[i][j] == '+');
            normal  += (mat[i][j] != '.');
        }
    }
    normal -= crosses;
    normal -= 2; // z y m
    // D(crosses);
    // D(normal);
        
    //For(i, 0, rows){For(j, 0, cols)printf("%c", mat[i][j]);printf("\n");}printf("\n");
    
    mustSeeNormal = normal;
    mustSeeCrosses = 2 * crosses;
    
    // mat[2][2] = '+';
    // check(start);
    // return 0;
    
    
    assert(start.first != -1 and start.second != -1);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat[i][j] != '.') continue;
            char options[] = {'|', '-', '+', '1', '2', '3', '4'};
            for (int k = 0; k < 7; ++k) {
                mat[i][j] = options[k];
                if (options[k] == '+') mustSeeCrosses += 2;
                if (options[k] != '+') mustSeeNormal += 1;
                
                if (check(start)) {
                    printf("%d %d %c\n", i + 1, j + 1, options[k]);
                    return 0;
                }
                
                if (options[k] == '+') mustSeeCrosses -= 2;
                if (options[k] != '+') mustSeeNormal -= 1;                
            }
            mat[i][j] = '.';
        }
    }
    
    return 0;
}