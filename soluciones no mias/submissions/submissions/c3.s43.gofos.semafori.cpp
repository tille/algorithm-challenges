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
bool lights [1005];
vector <pair <int, int> > t;

int main(){
    int N, L;
    cin >> N >> L;
    for (int i = 0; i < N; i++){
        int d, r, g;
        cin >> d >> r >> g;
        lights[d] = true;
        t.push_back(make_pair(r, g));
    }
    int pos = 0;
    int tiempo = 0;
    int next_light = 0;
    while (pos < L){
        if (lights[pos]){
            int r = t[next_light].first;
            int g = t[next_light].second;
            next_light++;
            if (tiempo % (r + g) < r){
                tiempo += tiempo % (r + g);
            }
        }
        pos++;
        tiempo++;
    }
    tiempo--;
    cout << tiempo << endl;
    
    
    
    
    return 0;
}