#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

char m[105][105];
int v[105][105];
int n;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> wss;
int t;

bool valid_index(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < n);
}

int bfs(int x, int y, int node) {
  queue<int> q;
  q.push(x);
  q.push(y);
  v[x][y] = 1;
  int res = 0;
  
  while (q.size()) {
    int xi = q.front(); q.pop();
    int yi = q.front(); q.pop();

    REP(i, 0, 7) {
      int xii = xi + dx[i];
      int yii = yi + dy[i];

      if (valid_index(xii, yii) && m[xii][yii] != 'b' && v[xii][yii] == 0) {
        if (m[xii][yii] != 'w') res++;
        v[xii][yii] = 1;
        q.push(xii);
        q.push(yii);
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    wss.clear();

    REP(i, 0, n - 1) {
      REP(j, 0, n - 1) {
        cin >> m[i][j];
        v[i][j] = 0;
        if (m[i][j] == 'b') v[i][j] = 1;

        if (m[i][j] == 'w') {
          wss.push_back(i); 
          wss.push_back(j);
        }
      }
    }

    // REP(i, 0, n - 1) {
    //   REP(j, 0, n - 1) {
    //     cout << v[i][j];
    //   }
    //   cout << endl;
    // }

    int ans = 0;
    for (int i = 0; i < wss.size(); i += 2) {
      ans = max(ans, bfs(wss[i], wss[i + 1], 0));
    }
    cout << ans << endl;
  }
  return 0;
}

