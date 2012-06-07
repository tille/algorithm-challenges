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

vector<string> friends;

bool tie(char a, char b) {
    return a == b;
}

bool win(char a, char b) {
    return (a == 'S' and b == 'P') or
           (a == 'P' and b == 'R') or
           (a == 'R' and b == 'S');
}

int main(){
    int n; cin >> n;
    string me; cin >> me;
    int k; cin >> k;
    friends.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> friends[i];
    }
    
    int score = 0;
    for (int i = 0; i < k; ++i) {
        for (int r = 0; r < n; ++r) {
            if ( win(me[r], friends[i][r]) ) score += 2;
            if ( tie(me[r], friends[i][r]) ) score += 1;
        }
    }
    printf("%d\n", score);
    
    score = 0;
    for (int r = 0; r < n; ++r) {
        int best = -1;
        char options[] = { 'S', 'R', 'P' };
        
        for (int k = 0; k < 3; ++k) {
            char me = options[k];
            int option = 0;
            for (int f = 0; f < friends.size(); ++f) {
                if ( win(me, friends[f][r]) ) option += 2;
                if ( tie(me, friends[f][r]) ) option += 1;
            }
            best = max(best, option);
        }
        score += best;
    }
    printf("%d\n", score);
    return 0;
}