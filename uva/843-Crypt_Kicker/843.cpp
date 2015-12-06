#include <bits/stdc++.h>

using namespace std;

typedef set<int> si; 
typedef map<char, char> msi;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) \
  for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define MAXN 10000

string decrypted[MAXN];
int n; 
bool ans; 
string line, endline, word;
vector<string> words;
string sol[1000];

bool match(msi B, const string &to, const string &from) {
  if (to.size() != from.size()) 
    return false;

  REP(i, 0, to.size() - 1) {
    if (B.count(from[i]) == 1) {
      if (B[from[i]] != to[i]) 
        return false;
    } else {
      TRmsi(B, it)
        if ((*it).second == to[i])
          return false;
      B[from[i]] = to[i];
    }
  }
  return true;
}

msi update_dictionary(msi A, const string &to, const string &from) {
  REP(j, 0, to.size() - 1) 
    A[from[j]] = to[j]; 
  return A;
}

bool backtrack(msi A, int c) {
  if (c == words.size()) 
    return true;

  REP(i, 0, n - 1) {
    if (match(A, decrypted[i], words[c])) {
      sol[c] = decrypted[i];
      if (backtrack(update_dictionary(A, decrypted[i], words[c]), c + 1)) 
        return true;
    }
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n;
  REP(i, 0, n - 1) cin >> decrypted[i];

  getline(cin, endline);
  while (getline(cin, line)) {
    if (line == "") break;
    words.clear();
    stringstream ss(line);

    while (ss >> word) 
      words.push_back(word);

    ans = backtrack(map<char, char>() , 0);
    REP(i, 0, words.size() - 1) {
      if (i) cout << " ";
      if (ans) cout << sol[i];
      else {
        string res(words[i].size(), '*');
        cout << res;
      }
    }
    cout << endl;
  }
  return 0;
}
