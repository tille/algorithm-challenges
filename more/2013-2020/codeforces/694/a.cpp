#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1<<30;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;

    ll maxi = 0, mini = 0;
    REP(i, 0, n-1) {
      ll num;
      cin >> num;
      mini += num;
      maxi += num/k;

      if (num % k) {
        maxi++;
      }
    }
    mini = ceil(mini/(double)k);
    cout << mini << " " << maxi << endl;
  }

  return 0;
}