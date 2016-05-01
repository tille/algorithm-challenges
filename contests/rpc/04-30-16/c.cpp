#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define K 1000000007

struct state {
  int c, sum, d;
  state() {}
  state(int _c, int _sum, int _d) {
    c = _c, sum = _sum, d = _d;
  }
  bool operator < (const state &other) const {
    ii a(c, sum);
    ii b(other.c, other.sum);
    return a < b;
  }
};

map<state, int> memo;
int k;

int calc(int c, int sum, int d) {
  state cur(c, sum, d);
  if (memo.count(cur) == 1) return memo[cur];
  if (!c) return memo[cur] = (sum == k) ? 1 : 0;

  int ans = 0;
  REP(i, 0, 1) {
    int newSum = (d == i) ? sum : sum + 1;
    ans = ((ans % K) + (calc(c - 1, newSum, i) % K)) % K;
  }
  return memo[cur] = ans;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n; 

  while (cin >> n >> k) {
    memo.clear();
    cout << (calc(n - 1, 0, 0) * 2) % K << endl;
  }
  return 0;
}

