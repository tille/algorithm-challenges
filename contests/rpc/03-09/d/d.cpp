#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

ll n, n2;
double x, p1, p2, p3;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout << fixed << setprecision(6); 

  while (cin >> n && n) {
    n2 = n * 2;
    x = (n2 * (n2 + 2)) / (4 * n);
    p1 = ((n2 + 1) * (n2 + 2) * n2) / 6;
    p2 = 2 * x * ((n2 * (n2 + 2)) / 4); 
    p3 = n * (x * x);
    
    cout << sqrt( (p1 - p2 + p3) / double(n - 1) ) << endl;
  }
  return 0;
}

