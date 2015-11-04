#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > lines;

#define EPS 1e-9

double x11, x22;

string calc() {
  int n = lines.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int x0 = 0; int y0 = lines[i].second;
      int x1 = 1; int y1 = lines[i].first + y0;  

      int x2 = 0; int y2 = lines[j].second;
      int x3 = 1; int y3 = lines[j].first + y2;

      double t0 = (y3-y2)*(x0-x2)-(x3-x2)*(y0-y2);
      double t1 = (x1-x0)*(y2-y0)-(y1-y0)*(x2-x0);
      double det = (y1-y0)*(x3-x2)-(y3-y2)*(x1-x0);

      if (fabs(det) >= EPS) {
        t0 /= det;
        t1 /= det;
        double x = x0 + t0*(x1-x0);
        double y = y0 + t0*(y1-y0);
        // printf("POINT %.2lf %.2lf\n", x, y);

        if (x11 < x && x < x22) return "yes";
      }
    }
  }
  return "no";
}

int main() {
  int n, ki, bi;

  cin >> n;
  cin >> x11 >> x22;

  for (int i = 0; i < n; ++i) {
    cin >> ki >> bi;
    lines.push_back( make_pair(ki, bi) );
  }

  cout << calc() << endl;

  return 0;
}
