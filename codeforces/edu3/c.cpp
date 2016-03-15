#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, s, up, down, top, bottom, ans;
int a[100005];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n;

  s = 0;
  REP(i, 0, n - 1) {
    cin >> a[i];
    s += a[i];
  }
  sort(a, a + n);
  
  up = s % n;
  top = ceil(s / double(n));
  bottom = floor(s / n);
  ans = 0;
  
  REP(i, 0, up - 1) 
    ans += abs(a[n-i-1] - top);
  for (int i = n - up - 1; i >= 0; i--)  
    ans += abs(a[i] - bottom);

  cout << ans / 2 << endl;

  return 0;
}

