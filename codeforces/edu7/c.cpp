#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, m, l, r, x;
int a[200011];
int nxt[200011];

int main() {
  scanf("%d%d", &n, &m);
  REP(i, 1, n) {
    scanf("%d", &a[i]);
  }

  nxt[n] = n + 1;
  for (int i = n - 1; i > 0; --i) {
    if (a[i] != a[i + 1]) nxt[i] = i + 1;
    else nxt[i] = nxt[i + 1];
  }

  while (m--) {
    scanf("%d%d%d", &l, &r, &x);
    if (a[l] != x) printf("%d\n", l);
    else {
      if (nxt[l] > r) printf("-1\n");
      else printf("%d\n", nxt[l]);
    }
  }
  return 0;
}

