#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

vector<int> arr[100];

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  
  int t, m, c, num;

  cin >> t;
  while (t--) {
    cin >> m >> c;
    REP(i, 0, m - 1) arr[i].clear();

    REP(i, 0, c - 1) {
      cin >> num;
      arr[num % m].push_back(num);
    }

    REP(i, 0, m - 1) {
      cout << i << " -> ";
      REP(j, 0, arr[i].size() - 1) {
        cout << arr[i][j] << " -> ";
      }
      cout << "\\" << endl;
    }
    if(t) cout << endl;
  }


  return 0;
}

