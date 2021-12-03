#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int t, m, n, k, kk;
char arr[55][55];
string s;
vector<string> words;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool valid_index(int i, int j) {
  return (i >= 0 && i < m && j >= 0 && j < n);
}

bool run_direction(int i, int j, int k, int dir, int c) {
  if (c == words[k].size()) return true;
  int ans = (arr[i][j] == words[k][c]) ? 1 : 0;
  return ans && run_direction(i + dy[dir], j + dx[dir], k, dir, c + 1);
}

int possible(int i, int j, int k, int dir) {
  int finY = i + ((words[k].size() - 1) * dy[dir]),
      finX = j + ((words[k].size()  - 1) * dx[dir]);
  return valid_index(finY, finX);
}

bool check(int i, int j, int k) {
  REP(dir, 0, 7)
    if (possible(i, j, k, dir) && run_direction(i, j, k, dir, 0))
      return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cin >> t;

  while (t--) {
    cin >> m >> n;
    words.clear();

    REP(i, 0, m - 1) {
      REP(j, 0, n - 1) {
        cin >> arr[i][j];
        arr[i][j] = tolower(arr[i][j]);
      }
    }

    cin >> kk;
    REP(i, 0, kk - 1) {
      cin >> s;
      REP(j, 0, s.size() - 1)
        s[j] = tolower(s[j]);
      words.push_back(s);
    }

    REP(k, 0, kk - 1) {
      bool valid = false;
      REP(i, 0, m - 1) {
        REP(j, 0, n - 1) {
          if (check(i, j, k)) {
            cout << i + 1 << " " << j + 1 << endl;
            valid = true;
            break;
          }
        }
        if (valid) break;
      }
    }
    if (t) cout << endl;
  }
  return 0;
}

