#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int num, x, y;

int main() {
  REP(i, 1, 5) {
   REP(j, 1, 5) {
      cin >> num;
      if (num == 1) {
        x = j; 
        y = i;
      }
    }
  }

  cout << abs(x - 3) + abs(y - 3) << endl;
  return 0;
}

