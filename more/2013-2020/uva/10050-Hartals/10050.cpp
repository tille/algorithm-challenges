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
#define MAXN 105

int parties[MAXN];
int hartals[MAXN];

int main() {
  int t, parties_n, n, ans, day;
  scanf("%d", &t);
  while (t--) {
    memset(hartals, 0, sizeof hartals);
    scanf("%d", &n);
    scanf("%d", &parties_n);
    ans = 0;

    REP(i, 0, parties_n - 1)
      scanf("%d", &parties[i]);

    int count = 1;
    REP(i, 1, n) {
      count++;
      bool lose_day = false;
      REP(j, 0, parties_n - 1) {
        hartals[j]++;
        if (hartals[j] == parties[j]) {
          lose_day = true;
          hartals[j] = hartals[j] % parties[j];
        }
      }
      day = (i - 1) % 7;
      if (lose_day && day != 5 && day != 6) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}

