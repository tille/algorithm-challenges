#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int t;
map<char, int> frq;
string str;

string letters[10] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cin >> t; 

  REP(tt, 1, t) {
    cin >> str;
    frq.clear();

    REP(i, 0, str.size() - 1)
      frq[str[i]]++;

    int res = 0;

    REP(i, 0, 9) {
      int ans;
      bool valid = true;
      string cur = letters[i];

      ma<char, int> nn;
      REP(kk, 0, cur.size() - 1) {
        if (!nn[cur[i]]) {
          nn[cur[i]]++;
        } else {
          cur.erase(cur.begin() + kk);
        }
      }

      REP(j, 0, cur.size() - 1) {
        int count = frq[cur[j]];

        if (!count) {
          valid = false;
          break;
        }
        ans = (j != 1) ? __gcd(ans, count) : count;
      }

      if (!valid) continue;

      REP(kk, 1, ans) {
        res = res * 10;
        res += i;
      }
    }

    cout << res << endl;
  }
  return 0;
}

