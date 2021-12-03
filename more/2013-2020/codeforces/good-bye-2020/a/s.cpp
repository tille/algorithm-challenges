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
  int a; cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi a(n);
    int sum = 0;

    REP(i,0,n-1) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());

    set<int> s;
    REP(i,0,n-1) {
      REP(j,i+1,n-1) {
        int val = abs(a[i] - a[j]);
        s.insert(val);
      }
    }
    cout << s.size() << endl;
  }

  return 0;
}