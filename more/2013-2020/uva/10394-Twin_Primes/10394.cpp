#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define maxn 20000000

map<int, ii> ans;
int sieve[maxn];

void build_sieve() {
  memset(sieve, false, sizeof sieve);
  sieve[0] = sieve[1] = true;

  for (int i = 2; i * i < maxn; ++i) {
    if (!sieve[i]) {
      for (int j = i * i; j < maxn; j += i) {
        sieve[j] = true;
      }
    }
  }

  int tc = 1;
  for (int i = 0; i < maxn - 2; ++i) {
    if (!sieve[i] && !sieve[i + 2]) {
      ans[tc++] = make_pair(i, i + 2);
    }
  }
}

int main() {
  int n;
  build_sieve();

  while (scanf("%d", &n) != EOF) {
    printf("(%d, %d)\n", ans[n].first, ans[n].second);
  }
   
  return 0;
}

