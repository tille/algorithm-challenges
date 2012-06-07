using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin();  \
                           x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

//Graham scan: Complexity: O(n log n)
struct point{
  int x,y;
  point() {}
  point(int X, int Y) : x(X), y(Y) {}
};

point pivot;

inline int distsqr(const point &a, const point &b){
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

inline double dist(const point &a, const point &b){
  return sqrt(distsqr(a, b));
}

//retorna > 0 si c esta a la izquierda del segmento AB
//retorna < 0 si c esta a la derecha del segmento AB
//retorna == 0 si c es colineal con el segmento AB
inline
int cross(const point &a, const point &b, const point &c){
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

//Self < that si esta a la derecha del segmento Pivot-That
bool angleCmp(const point &self, const point &that){
  int t = cross(pivot, that, self);
  if (t < 0) return true;
  if (t == 0){
    //Self < that si está más cerquita
    return (distsqr(pivot, self) < distsqr(pivot, that));
  }
  return false;
}

vector<point> graham(vector<point> p){
  if(p.size() < 3) return p;
  //Metemos el más abajo más a la izquierda en la posición 0
  for (int i=1; i<p.size(); ++i){
    if (p[i].y < p[0].y ||
        (p[i].y == p[0].y && p[i].x < p[0].x))
      swap(p[0], p[i]);
  }

  pivot = p[0];
  sort(p.begin(), p.end(), angleCmp);

  //Ordenar por ángulo y eliminar repetidos.
  //Si varios puntos tienen el mismo angulo el más lejano
  //queda después en la lista
  vector<point> chull(p.begin(), p.begin()+3);

  //Ahora sí!!!
  for (int i=3; i<p.size(); ++i){
    while (chull.size() >= 2 &&
           cross(chull[chull.size()-2],
                 chull[chull.size()-1],
                 p[i]) <=0){
      chull.erase(chull.end() - 1);
    }
    chull.push_back(p[i]);
  }
  //chull contiene los puntos del convex hull ordenados
  //anti-clockwise.  No contiene ningún punto repetido.  El
  //primer punto no es el mismo que el último, i.e, la última
  //arista va de chull[chull.size()-1] a chull[0]
  return chull;
}

/*
  Returns true if point (x, y) lies inside (or in the border)
  of box defined by points (x0, y0) and (x1, y1).
*/
bool point_in_box(double x, double y,
                  double x0, double y0,
                  double x1, double y1){
  return
    min(x0, x1) <= x && x <= max(x0, x1) &&
    min(y0, y1) <= y && y <= max(y0, y1);
}

/*
  Finds the intersection between two segments (Not infinite
  lines!)
  Segment 1 goes from point (x0, y0) to (x1, y1).
  Segment 2 goes from point (x2, y2) to (x3, y3).

  (Can be modified to find the intersection between a segment
  and a line)

  Handles the case when the 2 segments are:
  *Parallel but don't lie on the same line (No intersection)
  *Parallel and both lie on the same line (Infinite
  *intersections or no intersections)
  *Not parallel (One intersection or no intersections)

  Returns true if the segments do intersect in any case.
*/
bool segment_segment_intersection(double x0, double y0,
                                  double x1, double y1,

                                  double x2, double y2,
                                  double x3, double y3){
#ifndef EPS
#define EPS 1e-9
#endif

  double t0 = (y3-y2)*(x0-x2)-(x3-x2)*(y0-y2);
  double t1 = (x1-x0)*(y2-y0)-(y1-y0)*(x2-x0);
  double det = (y1-y0)*(x3-x2)-(y3-y2)*(x1-x0);
  if (fabs(det) < EPS){
    //parallel
    if (fabs(t0) < EPS || fabs(t1) < EPS){
      //they lie on same line, but they may or may not intersect.
      return (point_in_box(x0, y0,   x2, y2, x3, y3) ||
              point_in_box(x1, y1,   x2, y2, x3, y3) ||
              point_in_box(x2, y2,   x0, y0, x1, y1) ||
              point_in_box(x3, y3,   x0, y0, x1, y1));
    }else{
      //just parallel, no intersection
      return false;
    }
  }else{
    t0 /= det;
    t1 /= det;
    /*
      0 <= t0 <= 1 iff the intersection point lies in segment 1.
      0 <= t1 <= 1 iff the intersection point lies in segment 2.
    */
    if (0.0 <= t0 && t0 <= 1.0 && 0.0 <= t1 && t1 <= 1.0){
      double x = x0 + t0*(x1-x0);
      double y = y0 + t0*(y1-y0);
      //intersection is point (x, y)
      return true;
    }
    //the intersection points doesn't lie on both segments.
    return false;
  }
}
double turn(const point &a, const point &b, const point &c){
  double z = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
  if (fabs(z) < 1e-9) return 0.0;
  return z;
}
/*
  Returns true if point a is inside convex polygon p.  Note
  that if point a lies on the border of p it is considered
  outside.

  We assume p is convex! The result is useless if p is
  concave.
*/
bool insideConvexPolygon(const vector<point> &p,
                         const point &a){
  int mask = 0;
  int n = p.size();
  for (int i=0; i<n; ++i){
    int j = (i+1)%n;
    double z = turn(p[i], p[j], a);
    if (z < 0.0){
      mask |= 1;
    }else if (z > 0.0){
      mask |= 2;
    }else if (z == 0.0) return false;
    if (mask == 3) return false;
  }
  return mask != 0;
}

bool collision(const vector<point> & a, const vector<point> & b){
  for(int i = 0; i < a.size(); ++i)
    {
      int k = (i+1) % a.size();
      double x0 = a[i].x, y0 = a[i].y;
      double x1 = a[k].x, y1 = a[k].y;
      for(int j = 0; j < b.size() ; ++j)
        {
          int p = (j+1) % b.size();
          double x2 = b[j].x , y2 = b[j].y;
          double x3 = b[p].x , y3 = b[p].y;
          if(segment_segment_intersection(x0, y0, x1, y1,
                                          x2, y2, x3, y3))
            return true;
        }
    }
  return false;
}
int main(){
  int n, m;
  while(cin >> n >> m)
    {
      if(n == 0 and m == 0) break;
      vector<point> black,white;
      int x,y;
      for(int i = 0 ; i < n and cin >> x >> y; ++i)
        black.push_back(point(x,y));
      for(int i = 0 ; i < m and cin >> x >> y; ++i)
        white.push_back(point(x,y));
      vector<point> pb = graham(black), pw = graham(white);
      if(collision(pb, pw))
        puts("NO");
      else
        {
          if(insideConvexPolygon(pb, pw[0]) or insideConvexPolygon(pw, pb[0]))
            puts("NO");
          else
            puts("YES");
        }
    }
  return 0;
}
