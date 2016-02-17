#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
const int maxn = 10000005;

vector<ii> nums;
ll num, n, ans;
int tree[maxn];

ll sorting(ii i, ii j) {
  return i.first < j.first;
}

int get(int i) {
  int s = 0;
  for(; i; i -= i&-i) s += tree[i];
  return s;
}

int add(int i, int v) {
  for(; i < maxn; i += i&-i) tree[i] += v;
}

int main() {
  cin >> n;
  memset(tree, 0 , sizeof tree);
  ans = 0;

  REP(i, 1, n) {
    cin >> num;
    nums.push_back(make_pair(num, i));
  }
  sort(nums.begin(), nums.end(), sorting);

  REP(i, 0, nums.size() - 1) {
    ans += nums[i].second - 1 - get(nums[i].second);
    add(nums[i].second, 1);
  }

  cout << ans << endl;
  return 0;
}
