#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;

const int inf = 1<<30;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int const MAXN = 10e6;

vi g[MAXN];
bool seen[MAXN];
ll szs[MAXN];

void dfs(int u) {
  if (!g[u].size()) {
    seen[u] = true;
    szs[u] = 1;
    return;
  }

  for (auto v: g[u]) {
    if (!seen[v]) {
      dfs(v);
    }
    szs[u] += szs[v];
  }
  seen[u] = true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll num;
  vi nums;

  while (cin >> num) {
    nums.pb(num);
  }
  nums.pb(0);
  sort(nums.begin(), nums.end());
  nums.pb(nums[nums.size() - 1] + 3);

  REP(i, 0, nums.size()-2) {
    REP(j, i+1, nums.size()-1) {
      int dist = nums[j] - nums[i];
      if (dist <= 3) {
        g[nums[i]].pb(nums[j]);
      } else if (dist > 3) break;
    }
  }

  memset(seen, false, sizeof seen);
  memset(szs, 0, sizeof szs);
  int u = nums[0];
  dfs(u);
  cout << szs[u] << endl;

  // for (auto u: nums) {
  //   cout << u << ": ";
  //   for (auto v: g[u]) {
  //     cout << v << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}