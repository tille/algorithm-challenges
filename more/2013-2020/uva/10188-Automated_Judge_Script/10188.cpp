#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n, m;
string line;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int tc = 1;

  while (cin >> n && n) {
    string answers = "", attempts = "", nums[2] = {"", ""};
    getline(cin, line); // endline

    REP(i, 0, n - 1) {
      getline(cin, line);
      answers += line;
      REP(j, 0, line.size() - 1) if (isdigit(line[j])) nums[0] += line[j];
    }

    cin >> m;
    getline(cin, line); // endline

    REP(i, 0, m - 1) {
      getline(cin, line);
      attempts += line;
      REP(j, 0, line.size() - 1) if (isdigit(line[j])) nums[1] += line[j];
    }

    cout << "Run #" << tc++ << ": ";
    if (answers == attempts && n == m) cout << "Accepted";
    else if (nums[0] == nums[1]) cout << "Presentation Error";
    else cout << "Wrong Answer";
    cout << endl;
  }
   
  return 0;
}
