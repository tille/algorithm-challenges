#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

ll q, e, num;
set<ll> nums;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> q >> e; 

  REP(i, 0, e - 1) {
    cin >> num;
    nums.insert(num);
  }

  REP(j, 0, q - 1) {
    cin >> num;
    if (nums.count(num)) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
      nums.insert(num);
    }
  }
  return 0;
}

