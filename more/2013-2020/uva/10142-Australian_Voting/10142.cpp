#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

int t, n, k;
char endline;
string vote;
string names[25];
int votes[1005][25];
int col[1005];
int results[25];
set<int> eliminated;

bool choose_winner(int n, int k) {
  int major = -1, minor = 1<<30;
  REP(i, 0, n - 1) {
    if (eliminated.count(i) == 0) {
      major = max(major, results[i]);
      minor = min(minor, results[i]);
    }
  }
  int mid = int(k / 2);

  if (major == minor) return true;
  if (major > mid) {
    REP(i, 0, n - 1) {
      if (results[i] != major)
        eliminated.insert(i);
    }
    return true;
  }
  REP(i, 0, n - 1) 
    if (results[i] == minor) 
      eliminated.insert(i);
  return false;
}

int main() {
  scanf("%d", &t); 
  while (t--) {
    eliminated.clear();
    memset(col, 0, sizeof col);
    scanf("%d", &n); scanf("%c", &endline); 

    // read names
    REP(i, 0, n - 1) 
      getline(cin, names[i]);

    for (k = 0; true; ++k) {
      getline(cin, vote); 
      if (vote == "") break;

      stringstream ss(vote);
      REP(j, 0, n - 1) {
        ss >> votes[k][j];
        votes[k][j]--;
      }
    }

    do {
      memset(results, 0, sizeof results);
      REP(row, 0, k - 1) {
        while (eliminated.count(votes[row][col[row]]) != 0) 
          col[row]++;
        results[votes[row][col[row]]]++;
      }
    } while (!choose_winner(n, k));

    REP(i, 0, n - 1)
      if (eliminated.count(i) == 0)
        printf("%s\n", names[i].c_str());

    if (t) printf("\n");
  }
  return 0;
}

