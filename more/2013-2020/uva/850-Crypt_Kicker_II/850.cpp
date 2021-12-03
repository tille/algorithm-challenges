#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef map<char, char> mc;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int sizeW[9] = {3, 5, 5, 3, 5, 4, 3, 4, 3};
string res = "the quick brown fox jumps over the lazy dog";
vector<string> lines;
vector<mc> alphas;
int t;
string line;

void possible_alpha(string &line) {
  stringstream ss(line);
  int it = 0;
  string str;

  while (ss >> str) 
    if (str.size() != sizeW[it++]) return;

  mc alpha;
  bool valid = true;
  REP(i, 0, line.size() - 1) {
    if (alpha.find(line[i]) != alpha.end() && alpha[line[i]] != res[i]) {
      valid = false;
      break;
    }
    alpha[line[i]] = res[i];
  }
  if (valid) 
    alphas.push_back(alpha);
}

void decode_line(string &line, int k) {
  REP(i, 0, line.size() - 1)
    cout << alphas[k][line[i]];
  cout << endl;
}

void decipher(int k) {
  REP(i, 0, lines.size() - 1)
    decode_line(lines[i], k);
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cin >> t;
  getline(cin, line); // endline
  getline(cin, line); // blankline

  while (t--) {
    alphas.clear();
    lines.clear();

    while (getline(cin, line)) {
      if (line.size() == 0) break;
      possible_alpha(line);
      lines.push_back(line);
    }

    if (!alphas.size()) cout << "No solution." << endl;
    else decipher(0);
    
    if (t) cout << endl;
  }
  return 0;
}

