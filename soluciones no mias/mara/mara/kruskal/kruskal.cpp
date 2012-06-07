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

#define INPUT_FILE "kruskal"

bool isPrime(long long x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; 1LL * i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

const int MAXN = 7 * (int)1e7;

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
    primes.push_back(2);
    for (int i = 3; i <= MAXN; i += 2) {
        if (!criba[i]) {
            primes.push_back(i);
            // if (i < 100) D(i);
        }

    }
}


vector<long long> dist;

bool isWinning(long long morro, long long k) {
    if (morro % (k + 1) == 0) {
        return false;
    }
    return true;
    
    long long p = 1;
    while (p * k + p <= morro) {
        if (morro == p * k + p) return false;
        p++;
    }
    return true;
}

void solve() {
    int n;
    long long k; cin >> n >> k;
    
    if (n == 0) {
        puts("NO");
        return;
    }
    
    dist.resize( n );
    int primeCount = 0;
    
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;

        if (isPrime(x)) {
            primeCount++;
        }
  
        x--;
        int prime = x;
        if (x > 2) {
            if (x % 2 == 0) prime--;
            while (!isPrime(prime)) prime -= 2;;
        }
        // D(prime);

        dist[i] = x - prime + 1;
        assert( dist[i] > 0 );
    }
    
    if (primeCount >= 1 and n > 1) {
        puts("YES");
        return;
    }
    
    int ones = 0;
    for (int i = 0; i < n; ++i) {
        if ( isWinning(dist[i], k) ) {
            ones++;
        }
    }
    if (ones % 2 == 0) {
        puts("NO");
    } else {
        puts("YES");
    }
}

int main(){
    freopen(INPUT_FILE ".in", "r", stdin); // Read from file
    // buildCriba();
    // D(primes.size());
    // D(primes.back());
    
    int T; scanf("%d", &T);
    while (T--) {
        solve();
    }
    
    return 0;
}
