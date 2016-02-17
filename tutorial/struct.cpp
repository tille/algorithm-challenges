struct point {
  int x, y;
  point (int X, int Y) : x(X), y(Y) {}

  bool operator < (const point &other) const {
    if (x < other.x) return true;
    else if (x == other.x) {
      if (y < other.y) return true;
      else return false;
    }
    else return false;
  }
};

usage:
vector <point> v;
v.push_back(point(x, y));
sort(v.begin(), v.end());
