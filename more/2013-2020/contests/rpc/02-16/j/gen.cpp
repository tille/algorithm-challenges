#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  freopen("in3", "w", stdout);

  srand (time(NULL));
  for (int i = 0; i < 10000; ++i) {
    int len = rand() % 20 + 1;
    string str = "";

    REP(i, 0, len) {
      char letter = 'a' + int(rand() % 3);
      str += letter;
    }
    cout << str << endl;
  }
  return 0;
}

