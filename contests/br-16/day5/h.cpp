#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

ll n, pos;
vector<ll> locations;
bool valid;

int main() {
  while (cin >> n && n) {
    locations.clear();
    valid = true;

    REP(i, 0, n - 1) {
      cin >> pos;
      locations.push_back(pos);
    }
    sort(locations.begin(), locations.end());

    REP(i, 1, locations.size() - 1) {
      if (locations[i] - locations[i - 1] > 200) {
        valid = false;
        break;
      }
    }
    if (locations[locations.size() - 1] < 1322) valid = false;
    cout << ((valid) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  }
  return 0;
}

