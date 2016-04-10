#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

ll n, t;
char d;
string line, edge, res;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  while (cin >> n >> t >> d) {
    getline(cin, res); // endline
    if (d == 'L') t = t * -1; 

    getline(cin, edge);
    getline(cin, line);
    getline(cin, edge);

    cout << edge << endl;

    res = "";
    string ans = "";
    REP(i, 0, line.size() - 1) {
      if (line[i] != '|') {
        res += line[i];
        ans += " ";
      }
    }

    REP(i, 0, res.size() - 1) { 
      ll pos = (i + t + res.size()) % res.size();
      ans[pos] = res[i];
    }

    REP(i, 0, line.size() - 1) {
      if (i % 2) cout << ans[int(i / 2)];
      else cout << '|';
    }
    cout << endl;
    cout << edge << endl;
  }
   
  return 0;
}

