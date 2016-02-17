#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, num;
int a[105];

int main() {
  cin >> n;
  REP(i, 1, n) {
    cin >> num;
    a[num] = i;
  }
  REP(i, 1, n) {
    if (i != 1) cout << " ";
    cout << a[i];
  }
  puts("");
  return 0;
}

