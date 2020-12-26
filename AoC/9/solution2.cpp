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

vi prefix;
vi nums;

int find_major(int i, int j) {
  ll ans = 0;
  REP(it, i, j) {
    if (nums[it] > ans) ans = nums[it];
  }
  return ans;
}

int find_lower(int i, int j) {
  ll ans = inf;
  REP(it, i, j) {
    if (nums[it] < ans) ans = nums[it];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int num, idx = 0;

  cin >> num;
  prefix.pb(num);
  nums.pb(num);

  while (cin >> num) {
    nums.pb(num);
    prefix.pb(prefix[prefix.size()-1] + num);
  }

  int choose = 1492208709;
  REP(i, 2, prefix.size()) {
    REP(j, 0, prefix.size() - i) {
      ll sum;
      if (j-1 < 0) {
        sum = prefix[j+(i-1)];
      } else {
        sum = prefix[j+(i-1)] - prefix[j-1];
      }
      if (sum == choose) {
        ll minor = find_lower(j, j+(i-1));
        ll major = find_major(j, j+(i-1));
        cout << minor + major << endl;
        return 0;
      }
    }
  }

  return 0;
}