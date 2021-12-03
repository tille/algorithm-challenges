#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

string s;
int l;

int main() {
  cin >> s;
  l = 0;
  REP(i, 0, s.size()-1) {
    if (l == 0 && s[i] == 'h') l++;
    else if (l == 1 && s[i] == 'e') l++;
    else if (l == 2 && s[i] == 'l') l++;
    else if (l == 3 && s[i] == 'l') l++;
    else if (l == 4 && s[i] == 'o') l++;
    if (l == 5) break;
  }
  cout << ((l==5)?"YES":"NO") << endl;
  return 0;
}

