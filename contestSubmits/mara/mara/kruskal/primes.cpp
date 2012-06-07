using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); \
                           x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define INPUT_FILE "problemname"

const int MAXN = 1 * (int)1e9;

vector<int> primes;

bool criba[MAXN+1];
void buildCriba() {
    memset(criba, false, sizeof criba);
    criba[0] = criba[1] = true;
    for (int i = 4; i <= MAXN; i += 2) {
        criba[i] = true;
    }
    for (int i = 3; i * i <= MAXN; i += 2) {
        if (!criba[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                criba[j] = true;
            }
        }
    }
    for (int i = 3; i <= MAXN; i += 2) {
        if (!criba[i]) {
            printf("%d,", i);
            // if (i < 100) D(i);
        }
    }
}


int main(){
    printf("{2,");
    buildCriba();
    puts("};");
    return 0;
}
