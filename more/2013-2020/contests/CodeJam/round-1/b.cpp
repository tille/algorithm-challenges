#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define maxn 2505

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int t, num, n;
  cin >> t;

  REP(tc, 1, t) {
    cin >> n;
    vector<int> sum(maxn, 0);
    
    REP(i, 0, (n << 1) - 2) {
      REP(j, 0, n - 1) {
        cin >> num;
        sum[num]++;
      }
    }

    vector<int> ans;
    REP(i, 0, maxn - 1) {
      if (sum[i] % 2) {
        ans.push_back(i);
      }
    }

    sort(ans.begin(), ans.end());
    cout << "Case #" << tc << ": ";

    REP(i, 0, ans.size() - 1) {
      cout << ans[i];
      if (i != ans.size() - 1) cout << " ";
    }
    cout << endl;
  }
   
  return 0;
}

