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

  int d1 = 0, d3 = 0;
  REP(i, 1, nums.size()-1) {
    int sum = nums[i] - nums[i - 1];
    if (sum == 1) d1++;
    if (sum == 3) d3++;
  }
  cout << d1 * d3 << endl;

  return 0;
}