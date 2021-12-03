#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef map<string, int> msi;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int a, b, cur, ans = 0;
int segs[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
  cin >> a >> b; 
  REP(i, a, b) {
    cur = i;
    while (cur) {
      ans += segs[cur % 10];
      cur /= 10;
    }
  }
  cout << ans << endl;
  return 0;
}

