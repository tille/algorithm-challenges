#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

string a, b = "", c = "";
char p;
int f[30];
int n, mid;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> a;
  sort(a.begin(), a.end());

  p = a[0]; 
  b += p;
  f[p - 'a']++;
  REP(i, 1, a.size() - 1) {
    if (a[i] != p) b += a[i];
    f[a[i] - 'a']++;
    p = a[i];
  }

  REP(i, 0, b.size() - 1) 
    if (f[b[i] - 'a'] % 2) c += b[i];

  mid = c.size() / 2.0;
  n = c.size();
  REP(i, 1, mid) {
    if (c[i - 1] != c[n - i]) {
      f[c[n - i] - 'a']--;
      f[c[i - 1] - 'a']++;
    }
  }

  string ans = "";
  REP(i, 0, b.size() - 1) {
    int cant = f[b[i] - 'a'] / 2.0;
    REP(j, 0, cant - 1) {
      ans += b[i];
    }
  }
  b = ans;
  reverse(ans.begin(), ans.end());
  if (f[c[mid] - 'a'] % 2) b += c[mid];
  ans = b + ans;
  cout << ans << endl;

  return 0;
}
