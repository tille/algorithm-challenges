#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

ll n, i, res, limit;

int main() {
  cin >> n;
  res = 0, i = 0;
  while (res < n) {
    i++;
    res = (i * (i + 1)) / 2;
  }

  i--;
  limit = (i * (i + 1)) / 2;
  cout << n - limit << endl;
  return 0;
}

