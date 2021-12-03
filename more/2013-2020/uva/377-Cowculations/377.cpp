#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<char, char> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define push_back pb

char res[2];
char carries[30][30], results[30][30];

void addC(char d1, char d2) {
  res[0] = res[1] = '0';

  if (d1 == '0') res[0] = d2;
  else if (d2 == '0') res[0] = d1;
  else {
    res[0] = results[d1 - 'A'][d2 - 'A'];
    res[1] = carries[d1 - 'A'][d2 - 'A'];
  }
}

string add(string n1, string n2);

string Rshift(string &n) {
  return "V" + n.substr(0, n.size() - 1);
}

string Lshift(string &n) {
  return n + "V";
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  char letter[4] = {'V', 'U', 'C', 'D'};
  char r[16] = {'V', 'U', 'C', 'D', 'U', 'C', 'D', 'V', 'C', 'D', 'V', 'U', 'D', 'V', 'U', 'C'};
  char v[16] = {'0', '0', '0', '0', '0', '0', '0', 'U', '0', '0', 'U', 'U', '0', 'U', 'U', 'U'};

  int it = 0;
  REP(i, 0, 3) {
    REP(j, 0, 3) {
      carries[letter[i] - 'A'][letter[j] - 'A'] = v[it];
      results[letter[i] - 'A'][letter[j] - 'A'] = r[it++];
    }
  }

  string n1, n2, res, ans;
  int t; char c;

  cin >> t;
  cout << "COWCULATIONS OUTPUT" << endl;

  while (t--) {
    cin >> n1 >> n2;

    REP(i, 0, 2) {
      cin >> c;
      if (c == 'A') n2 = add(n1, n2);
      else if (c == 'R') n2 = Rshift(n2);
      else if (c == 'L') n2 = Lshift(n2);
    }

    n2 = string(8 - n2.size(), 'V') + n2;

    cin >> res;
    ans = (res == n2) ? "YES" : "NO";
    cout << ans << endl;
  }

  cout << "END OF OUTPUT" << endl;
  return 0;
}

// add two cow numbers
string add(string n1, string n2) {
  if (n2.size() > n1.size()) swap(n1, n2);

  n2 = string(n1.size() - n2.size(), '0') + n2;
  string ans = string(n1.size(), '0');

  char carry = '0';
  for (int i = n1.size() - 1; i >= 0; i--) {
    addC(n1[i], n2[i]); 
    char carry1 = res[1];

    addC(res[0], carry); 
    ans[i] = res[0];

    addC(res[1], carry1);
    carry = res[0];
  }

  if (carry != '0') ans = carry + ans;
  return ans;
}
