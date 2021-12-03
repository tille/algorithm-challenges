#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

// does not build the graph since create it gives TLE

vector<string> words[26000];
vector<int> p;
string u, v, word;
int tc = 0;

void printPath(vector<string> &ws, int pos_u, int pos_v) {
  vector<string> res;
  while (pos_v != pos_u) {
    res.push_back(ws[pos_v]);
    pos_v = p[pos_v];
  }
  cout << ws[pos_u] << endl;
  for (int i = res.size() - 1; i >= 0; i--) {
    cout << res[i] << endl;
  }
}

// void printPath(vector<string> ws, int ai, int zi) {
//   if (ai != zi)
//     printPath(ws, ai, p[zi]);
//   cout << ws[zi] << endl;
// }

bool areDoublets(string &a, string &b) {
  int d=0;
  for (size_t i = 0; i < a.length(); i++)  d+= (a[i]!=b[i]);
  return d==1;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  while (getline(cin, word) && word.size()) words[word.size()].push_back(word); 

  while (cin >> u >> v) {
    if (tc++) cout << endl;

    vector<string> ws = words[u.size()];
    int pos_u = find(ws.begin(), ws.end(), u) - ws.begin();
    int pos_v = find(ws.begin(), ws.end(), v) - ws.begin();
    
    if (pos_u == ws.size() || pos_v == ws.size() || u.size() != v.size()) {
      cout << "No solution." << endl;
    } else {
      queue<int> q;
      q.push(pos_u);

      p.clear();
      p.assign(ws.size() + 2, -1);

      while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur == pos_v) {
          printPath(ws, pos_u, pos_v);
          break;
        }

        REP(i, 0, ws.size() - 1) {
          if (p[i] == -1 && areDoublets(ws[cur], ws[i])) {
            p[i] = cur;
            q.push(i);
          }
        }
      }
      if (p[pos_v] == -1) cout << "No solution." << endl;
    }
  }
   
  return 0;
}

