#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, ans;
int ini[1005], fin[1005];
string s;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  memset(ini, 0, sizeof ini);
  memset(fin, 0, sizeof fin);

  cin >> n >> s;
  REP(i, 0, n - 1) ini[i] = s[i] - '0';

  cin >> s;
  REP(i, 0, n - 1) fin[i] = s[i] - '0';

  ans = 0;

  REP(i, 0, n - 1) {
    int c1 = abs(ini[i] - fin[i]);
    int c2 = (10 - fin[i]) + ini[i];
    int c3 = (10 - ini[i]) + fin[i];
    int temp = min(c1, min(c2, c3));

    ans += temp;
  }
  cout << ans << endl;
  return 0;
}

