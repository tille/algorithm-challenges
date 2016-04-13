#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

map<ii, int> v;
map<int, int> memo;

int g(int n) {
  return (n * (n + 1)) / 2;
}

int bfs(int n, int c) {
  queue<ii> q;
  ii ini = make_pair(0, 0);
  q.push(ini);

  if (memo.find(n) != memo.end()) 
    return memo[n];
  
  while (q.size()) {
    int cur = q.front().first;
    int cost = q.front().second;
    q.pop();

    for (int i = 1; g(i) + cur <= n; ++i) {
      int next = cur + g(i);

      if (memo.find(next) != memo.end()) memo[next] = cost + 1;
      if (next == n) return memo[n] = cost + 1;
      if (memo.find(n - next) != memo.end()) return memo[n] = memo[n - next] + cost + 1;

      ii nxt = make_pair(next, cost + 1);
      
      if (v.find(nxt) == v.end()) {
        v[nxt] = 1;
        q.push(nxt);
      }
    }
  }
  return 0; // should never get here
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n;
  
  while (cin >> n) {
    v.clear();
    cout << bfs(n, 0) << endl;
  }
  return 0;
}

