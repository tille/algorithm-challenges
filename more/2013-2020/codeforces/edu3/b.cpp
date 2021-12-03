#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, m, gi, pos, p;
vector<int> genres;
vector<int> a;
int f[15];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> m; 

  REP(i, 0, n - 1) {
    cin >> gi;
    genres.push_back(gi);
  }

  sort(genres.begin(), genres.end());

  p = genres[0]; pos = 0;
  REP(i, 1, genres.size() - 1) {
    if (genres[i] != p) {
      a.push_back(i - pos);
      pos = i;
      p = genres[i];
    }
  }
  a.push_back(genres.size() - pos);

  f[a.size() - 1] = a[a.size() - 1];
  for (int i = a.size() - 2; i >= 0; i--) {
    f[i] = a[i] + f[i + 1];
  }

  int ans = 0;
  REP(i, 0, a.size() - 2) {
    ans += a[i] * f[i + 1];
  }
  cout << ans << endl;

  return 0;
}

