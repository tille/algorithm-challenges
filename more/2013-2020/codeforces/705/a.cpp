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
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    if (i != 1) cout << " ";

    if (i%2) cout << "I hate ";
    else if (i%2 == 0) cout << "I love ";

    if (i == n) cout << "it";
    else cout << "that";
  }
  cout << endl;
  return 0;
}

