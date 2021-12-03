#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int a[5], b[5];

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
   
  REP(i, 0, 4) cin >> a[i];
  REP(i, 0, 4) cin >> b[i];

  bool valid = true;
  REP(i, 0, 4) {
    if (a[i] == b[i]) {
      valid = false;
      break;
    }
  }

  if (valid) 
    cout << "Y" << endl;
  else 
    cout << "N" << endl;
  return 0;
}

