#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, s, fi, ti;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> s; 
  int ans = 0;

  REP(i, 1, n) {
    cin >> fi >> ti;
    ans = max(ans, fi + ti);
  }

  cout << max(ans, s) << endl;

  return 0;
}

