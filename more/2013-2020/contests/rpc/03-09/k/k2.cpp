#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); ++i)
int indexes[25], pos[25];

int main() {
  int k, index; ll n;

  while (scanf("%lli", &n) != EOF) {
    scanf("%d", &k);

    REP(i, 0, k - 1) {
      scanf("%d", &index);

      indexes[i] = index;
      pos[i] = (n & (1LL << index)) ? 1 : 0;
    }

    sort(pos, pos + k);
    ll ans = 0;

    do {
      ll num = n;
      REP(i, 0, k - 1) {
        int bit = (num & (1LL << indexes[i])) ? 1 : 0;
        if (bit != pos[i]) num ^= (1LL << indexes[i]);
      }

      if (num % 7 == 0) ans = max(ans, num);
    } while (next_permutation(pos, pos + k));

    printf("%lli\n", ans);
  }
   
  return 0;
}

