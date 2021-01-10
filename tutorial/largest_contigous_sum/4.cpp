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

int lcs(vi &a) {
  int best = a[0], cur = a[0];
  for (int j = 1; j < a.size(); ++j) {
    cur = max(a[j], cur + a[j]);
    best = max(best, cur);
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  vi a(n);

  for(int i = 0; i < n; ++i) cin >> a[i];

  cout << lcs(a) << endl;
  return 0;
}