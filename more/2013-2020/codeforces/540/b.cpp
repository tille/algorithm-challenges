#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, k, p, x, y, sec, num, acum, fir;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> k >> p >> x >> y; 

  sec = acum = fir = 0;
  REP(i, 0, k - 1) {
    cin >> num;
    acum += num;
    if (num >= y) sec++;
    if (num < y) fir++;
  }

  int cm = (n+1)/2;
  int fm = (n-1)/2;
  
  if (fir >= cm) {
    cout << -1 << endl;
  } else {
    if (sec >= cm) {
      if (acum + (n - k) > x) {
        cout << -1 << endl;
      } else {
        REP(j, 1, n - k - 1) cout << "1 ";
        cout << 1 << endl;
      }
    } else {
      int cy = cm - sec;
      int c1 = fm - fir;

      if (((cy*y) + c1 + acum) > x) {
        cout << -1 << endl;
      } else {
        vector<int> a;
        REP(j, 1, c1) a.push_back(1);
        REP(j, 1, cy) a.push_back(y);
        REP(j, 0, a.size() - 2) cout << a[j] << " ";
        cout << a[a.size() - 1] << endl;
      }
    }
  }
  return 0;
}

