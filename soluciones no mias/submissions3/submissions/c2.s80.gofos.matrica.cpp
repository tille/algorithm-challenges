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

int have[26];
vector<int> cols;
string diagonal;

void buildDiagonal(int n) {
    string impares;
    
    for (int i = 0; i < 26; ++i) {
        if (have[i] % 2 == 1) {
            impares += char('A' + i);
            have[i]--;
        }
    }
    
    impares += char('Z' + 1); // sentinel
    int proximaImpar = 0;

    int j = 0, seen = 0;
    
    diagonal.resize( n );
    for (int i = 0; i < n; ++i) {
        
        while (seen >= have[j]) {
            seen -= have[j];
            j++;
        }
        
        char par = j + 'A';
        char impar = impares[proximaImpar];
        
        if (impar <= par) {
            diagonal[i] = impar;
            seen += 2 * (n - 1 - i);
            proximaImpar++;
            
        } else {
            diagonal[i] = diagonal[i + 1] = par;
            seen += 2 + 2 * (n - 1 - i   +    n - 2 - i);
            i++;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        have[ diagonal[i] - 'A' ]--;
    }
    for (int i = 0; i < impares.size(); ++i) {
        have[ impares[i] - 'A' ]++;
    }
    
    // for (int i = 0; i < 26; ++i) {
    //     if (have[i] > 0) printf("%c esta %d veces\n", i + 'A', have[i]);
    // }
    // D(diagonal);
}

void print(int i, int j, long long n) {
    if (i == j) {
        printf("%c", diagonal[i]);
        return;
    }
    if (i > j) swap(i, j);
    
    int s = 2 * ( i * n - i * (i + 1) / 2 ) + 2 * (j - i) - 2;
    
    // printf("i = %d, j = %d, s = %d\n", i, j, s);
    
    int k = 0, seen = s;
    while (seen >= have[k]) {
        seen -= have[k];
        k++;
    }
    printf("%c", k + 'A');
}

int main(){
    int n, m;
    scanf("%d %d ", &n, &m);

    int odd = 0;
    for (int i = 0; i < m; ++i) {
        char letra; int veces; scanf("%c %d ", &letra, &veces);
        have[letra - 'A'] = veces;
        
        odd += (veces % 2 == 1);
    }
    
    int P; scanf("%d", &P);
    cols.resize(P);
    for (int i = 0; i < P; ++i) {
        scanf("%d", &cols[i]);
        cols[i]--;
    }

    if (odd > n or (n - odd) % 2 == 1) {
        puts("IMPOSSIBLE");
        return 0;
    }
    
    buildDiagonal(n);
    for (int r = 0; r < n; ++r) {
        for (int k = 0; k < cols.size(); ++k) {
            int c = cols[k];
            print(r, c, n);
        }
        puts("");
    }
    
    
    return 0;
}