#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef long double ldd;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define PI 3.14159265
#define EPS 1e-9
#define AT 0.4330127018922193

struct point {
  ldd x, y;
  point() {}
  point (ldd _x, ldd _y) {
    x = _x, y = _y;
  }
};

int t, c, angle;
char dir;
ldd _x1, _y1, _xf, _yf, dista;
vector<point> points;
point pivot(0,0);

ldd area(const vector<point> &p) {
  ldd result = 0.0, x1, y1, x2, y2;
  REP(i, 0, p.size() - 2) {
    x1 = p[i].x; x2 = p[i+1].x;
    y1 = p[i].y; y2 = p[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> c;
    _xf = 0.0, _yf = 0.0;
    points.clear();

    REP(i, 0, c - 1) {
      cin >> dir >> dista;

      if (dir == 'x') _y1 = 0, _x1 = dista;

      if (dir != 'x') {
        angle = 60;
        _y1 = abs(dista * sin(angle * PI / 180));
        _x1 = abs(dista * cos(angle * PI / 180));

        if (dir == 'z' && dista >= 0) _x1 *= -1;
        else if (dir == 'y' && dista < 0) _x1 *= -1, _y1 *= -1; 
        else if (dir == 'z' && dista < 0) _y1 *= -1;
      }
      _xf = _x1 + _xf, _yf = _y1 + _yf;
      points.push_back(point(_xf, _yf)); 
    }

    cout << round(area(points) / AT) << endl;
  }
  return 0;
}
