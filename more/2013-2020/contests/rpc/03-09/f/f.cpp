#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MAXN 3000000

int memo[MAXN + 1];
int gauss[3000];

int g(int n) {
  if (gauss[n] != -1) return gauss[n];
  return gauss[n] = (n * (n + 1)) / 2;
}

void bfs(int tot) {
  queue<int> q;

  for (int i = 1; g(i) <= MAXN; ++i) {
    tot++;
    q.push(g(i));
    memo[g(i)] = 1;
  }
  
  while (q.size()) {
    int cur = q.front();
    q.pop();

    if (tot == MAXN) return ;

    for (int i = 1; g(i) <= cur; ++i) {
      int next = cur + g(i);

      if (next <= MAXN && memo[next] == -1) {
        tot++;
        memo[next] = memo[cur] + 1;
        q.push(next);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int n;
  memset(memo, -1, sizeof memo);
  memset(gauss, -1, sizeof gauss);
  bfs(0);
  
  while (cin >> n) {
    cout << memo[n] << endl;
  }
  return 0;
}

