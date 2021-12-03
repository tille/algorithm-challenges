#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef set<int> si; 
typedef map<string, int> msi;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) \
  for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int main() {
  int k, x, y, n, m;
  while (scanf("%d", &k) && k) {
    scanf("%d %d", &n, &m);
    REP(i, 0, k - 1) {
      scanf("%d %d", &x, &y);
      if (x == n || y == m) printf("divisa\n");
      else if (x > n && y > m) printf("NE\n");
      else if (x < n && y < m) printf("SO\n");
      else if (x < n && y > m) printf("NO\n");
      else printf("SE\n");
    }
  }
  return 0;
}

