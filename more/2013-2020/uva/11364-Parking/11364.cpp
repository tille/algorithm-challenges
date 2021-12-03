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
#define TRvi(c, it) \
  for (vi::iterator it = (c).begin(); it != (c).end(); it++) 
#define TRvii(c, it) \
  for (vii::iterator it = (c).begin(); it != (c).end(); it++) 
#define TRmsi(c, it) \
  for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int main() {
  int t, l, r, n, num;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n); l = 1 << 30; r = -1;

    REP(i, 0, n - 1) {
      scanf("%d", &num);
      l = min(l, num);
      r = max(r, num);
    }
    printf("%d\n", 2 * (r - l));
  }
  return 0;
}

