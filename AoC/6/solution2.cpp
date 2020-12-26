#include <bits/stdc++.h>

using namespace std;

#define ASCII 30
#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

int main() {
  set<char> s;
  string line;
  long ans = 0, linesC = 0;
  vector<int> frequency(ASCII, 0);

  while (getline(cin, line)) {
    if (line == "") {

      int temp = 0;
      REP(i, 0, frequency.size() - 1) {
        if (frequency[i] == linesC) {
          temp++;
        }
      }

      ans += temp;
      s.clear();
      frequency.assign(ASCII, 0);
      linesC = 0;
    } else {
      
      linesC++;
      for (auto i : line) 
        frequency[i - 'a']++;
    }
  }

  int temp = 0;
  REP(i, 0, frequency.size() - 1) {
    if (frequency[i] == linesC) {
      temp++;
    }
  }
  ans += temp;
  cout << ans << endl;

  return 0;
}