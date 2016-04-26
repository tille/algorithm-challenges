#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define maxn 105

int arr[maxn][maxn];
int n, m, ans;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
   
  while (cin >> n >> m) {
    ans = 0;
    REP(i, 0, n - 1) REP(j, 0, m - 1) cin >> arr[i][j];

    REP(i, 0, n - 1) {
      bool valid = true;
      REP(j, 0, m - 1) {
        if (arr[i][j] == 0) {
          valid = false;
          break;
        }
      }
      if (valid) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

