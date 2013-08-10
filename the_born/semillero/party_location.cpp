#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define pb push_back

struct point{
  double x, y;
  point(){}
  point(double x1, double y1){
    x = x1, y = y1;
  }
};

vector<point> p;

double dist(point p1, point p2){
  double x = p1.x - p2.x;
  double y = p1.y - p2.y;
  return sqrt(x*x + y*y);
}

int cmp(point center, double ratio){
  int cont = 0;
  if( ratio > 2.5 || ratio <= 0 ) return 0;
  for( int i = 0; i < p.size(); ++i ){
    double res = dist(p[i],center);
    if(res <= ratio) cont++;
  }
  return cont;
}

int main(){
  int ans = 0;
  double x,y,x2,y2,h;
  while( cin >> x >> y ) p.pb(point(x,y));
  
  for( int i = 0; i < p.size(); ++i ){
    for( int j = i+1; j < p.size(); ++j ){
      h = dist(p[i],p[j]);
      x2 = (p[i].x + p[j].x)/2;
      y2 = (p[i].y + p[j].y)/2;
      
      // nuevo vector perpedicular normalizado
      point u = point(-y2, x2);
      double mag_u = sqrt(u.x*u.x + u.y*u.y);
      u.x /= mag_u, u.y /= mag_u;
      
      // encontrando el centro y el radio
      double ratio = dist(point(x2,y2), point(u.x*h, u.y*h));      
      int temp = cmp(u,ratio);
      if(temp>ans) ans = temp;
    }
  }
  cout << ans << endl;
  return 0;
}