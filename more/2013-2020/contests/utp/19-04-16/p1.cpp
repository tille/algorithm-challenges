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
   
  int p, n;
  cin >> p >> n;

  int ini, num;
  cin >> ini;
  bool valid = true;
  REP(i, 1, n - 1) {
    cin >> num;
    if (abs(num - ini) > p) {
      valid = false;
    }
    ini = num;
  }

  if (valid) {
    cout << "YOU WIN" << endl;
  } else {
    cout << "GAME OVER" << endl;
  }
  return 0;
}

