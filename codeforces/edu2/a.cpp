#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

string s;
vector<string> words;
vector<string> nums;
int p = 0;
string word;

bool isWord(const string &w) {
  if (!w.size()) return true;
  if (w[0] == '0' && w.size() > 1) return true;
  REP(i, 0, w.size() - 1)
    if (!isdigit(w[i])) return true;
  return false;
}

void print_results();

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> s;

  REP(i, 0, s.size() - 1) {
    if (s[i] == ',' || s[i] == ';') {
      word = s.substr(p, i - p);
      
      if (isWord(word)) words.push_back(word);
      else nums.push_back(word);

      p = i + 1;
    }
  }

  word = s.substr(p, s.size() - p);
  if (isWord(word)) words.push_back(word);
  else nums.push_back(word);

  print_results();

  return 0;
}

void print_results() {
  if (nums.size() <= 0) {
    cout << "-" << endl;
  } else {
    cout << "\"";
    REP(i, 0, nums.size() - 2) {
      cout << nums[i] << ",";
    }
    cout << nums[nums.size() - 1];
    cout << "\"" << endl;
  }

  if (words.size() <= 0) {
    cout << "-" << endl;
  } else { 
    cout << "\"";
    REP(i, 0, words.size() - 2) {
      cout << words[i] << ",";
    }
    cout << words[words.size() - 1];
    cout << "\"" << endl;
  }
}
