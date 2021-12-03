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

  vi nums;

  ll n = 25, num;
  while (cin >> num) {
    nums.pb(num);

    if (nums.size() > n) {
      vi copy(nums.begin() + (nums.size() - n - 1), nums.end() - 1);
      sort(copy.begin(), copy.end());
      int i = 0; int j = n-1;

      while (i < j) {
        ll sum = copy[i] + copy[j];
        if (sum == num) break;
        else if (sum < num) i++;
        else j--;
      }
      if (i == j) {
        cout << num << endl;
        break;
      }
    }
  }
  return 0;
}