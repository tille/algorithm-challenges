#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  string line, str;

  while (getline(cin, line)) {
    stringstream ss(line);

    string ans = "";
    while (ss >> str) ans += str[0];

    getline(cin, line);
    stringstream sss(line);

    string res = "";
    while (sss >> str) res += str[0];

    if (ans == res) 
      cout << "yes" << endl;
    else 
      cout << "no" << endl;
  }
  return 0;
}

