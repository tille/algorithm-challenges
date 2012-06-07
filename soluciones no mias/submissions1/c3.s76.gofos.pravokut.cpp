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
vector < pair <long long, long long> > points;

long long d (long long x1, long long y1, long long x2, long long y2){
    long long x = x1 - x2;
    long long y = y1 - y2;
    return (x * x + y * y);
}

int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        long long x, y;
        cin >> x >> y;
        points.push_back(make_pair(x,y));
    }
    int count = 0;
    for (int i = 0; i < N; i++){
        long long x1 = points[i].first;
        long long y1 = points[i].second;
        for (int j = i + 1; j < N; j++){
            long long x2 = points[j].first;
            long long y2 = points[j].second;
            for (int k = j + 1; k < N; k++){
                long long x3 = points[k].first;
                long long y3 = points[k].second;
                if (d(x1, y1, x2, y2) + d(x1, y1, x3, y3) == d(x2, y2, x3, y3) or
                    d(x2, y2, x1, y1) + d(x2, y2, x3, y3) == d(x1, y1, x3, y3) or
                    d(x3, y3, x1, y1) + d(x3, y3, x2, y2) == d(x1, y1, x2, y2) ){
                    //printf("Entre cuando i = %d, j = %d, k = %d\n", i, j, k);
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}