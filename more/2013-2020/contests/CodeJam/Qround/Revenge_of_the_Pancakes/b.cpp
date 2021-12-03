#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<string, int> si;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int t;
string s, target, cur;
map<string, int> d;

int bfs(string from) {
  queue<string> q;
  d[from] = 0;
  q.push(from);

  while (s.size()) {
    cur = q.front();
    q.pop();

    if (cur == target) 
      return d[cur];

    string next = "", nextt;
    for (int i = 0; i < cur.size(); ++i){
      char inv = (cur[i] == '+') ? '-' : '+';
      next = inv + next;

      if (i + 1 == cur.size()) nextt = next;
      else nextt = next + cur.substr(i + 1, cur.size() - i - 1);

      if (d.find(nextt) == d.end()) {
        d[nextt] = d[cur] + 1;
        cout << d[cur] + 1 << endl;
        q.push(nextt);
      }
    }
  }
  return -1; // should never get here
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cin >> t;

  REP(tt, 1, t) {
    cin >> s;
    target = "";
    d.clear();

    REP(i, 0, s.size() - 1) target += "+";
    cout << "Case #" << tt << ": ";
    cout << bfs(s) << endl;
  }
   
  return 0;
}

