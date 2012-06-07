// Andrés Mejía y Ana Echavarría
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

int times [105];
int costs [3];
int main(){
    cin >> costs[0] >> costs[1] >> costs[2];
    for (int i = 0; i < 3; i++){
        int arrive, leave;
        cin >> arrive >> leave;
        for (int j = arrive; j < leave; j++){
            times[j]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < 105; i++){
        int num = times[i];
        if (num == 0) continue;
        ans += (num * costs[num - 1]);
    }
    
    cout << ans << endl;
    
    return 0;
}