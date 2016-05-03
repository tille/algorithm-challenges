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
  int a, b;
   
  while (cin >> a >> b) {
    cout << ceil((double)b / abs(a - b)) << endl;
  }
  return 0;
}

