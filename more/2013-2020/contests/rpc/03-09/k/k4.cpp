#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxK 20

int a[maxK], arr[maxK];

int main() {
  ll N;
  int K;
  while (scanf("%lld", &N) != EOF) {
    scanf("%d", &K);
    int c1s = 0;
    ll S = N;
    FOR(i, 0, K) {
      scanf("%d", a + i);
      if (N & 1LL << a[i]) {
        c1s++;
        S -= 1LL << a[i];
      }
    }
    FOR(i, 0, K - c1s) arr[i] = 0;
    FOR(i, K - c1s, K) arr[i] = 1;
    ll ans = 0;
    do {
      ll ts = S;
      FOR(i, 0, K) {
        if (arr[i]) {
          ts += 1LL << a[i];
        }
      }
      if (ts % 7 == 0) ans = max(ans, ts);
    } while (next_permutation(arr, arr+K));
    printf("%lld\n", ans);
  }
  return 0;
}
