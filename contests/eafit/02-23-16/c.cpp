#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int c[2] = {0, 0};
int n;
string s;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> s;
  REP(i, 0, n - 1) c[s[i] - '0']++;

  cout << s.size() - (2 * min(c[0], c[1])) << endl;
  return 0;
}

