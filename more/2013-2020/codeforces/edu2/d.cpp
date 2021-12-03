#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

ld _x1, _y1, _x2, _y2, _r1, _r2, d, dx, dy, ans;
const double PI = acos(-1.0);

ld angle(double r1, double r2) {
  ld temp = ((r1 * r1) + (d*d) - (r2 * r2)) / (2 * r1 * d);
  return acos(temp) * 2;
}

ld seg(ld angle, ld r) {
  return ((angle - sin(angle)) * (r*r)) / 2.0;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << fixed << setprecision(14);
  cin >> _x1 >> _y1 >> _r1;
  cin >> _x2 >> _y2 >> _r2;

  dx = fabs(_x1 - _x2);
  dy = fabs(_y1 - _y2);
  d = sqrt((dx * dx) + (dy * dy));

  if (d >= _r1 + _r2) 
    ans = 0.0;
  else if (d <= abs(_r1 - _r2)) 
    ans = PI * (min(_r1, _r2) * min(_r1, _r2));
  else {
    ans = seg(angle(_r1, _r2), _r1) + seg(angle(_r2, _r1), _r2);
  }

  cout << ans << endl;
  return 0;
}

