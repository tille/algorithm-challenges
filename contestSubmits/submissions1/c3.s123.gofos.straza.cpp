// Andrés Mejía
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
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

////////////// Prewritten code follows. Look down for solution. ////////////////
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
////////////////////////// Solution starts below. //////////////////////////////

struct point {
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    
    bool operator < (const point &other) const {
        int c = cmp(x, other.x);
        if (c != 0) return c < 0;
        c = cmp(y, other.y);
        return c < 0;
    }
};

typedef pair<point, point> segment;


bool point_in_box(double x, double y,   double x0, double y0,   double x1, double y1) {
    return cmp(min(x0, x1), x) <= 0 and cmp(x, max(x0, x1))  <= 0 and
        cmp(min(y0, y1), y) <= 0 and cmp(y, max(y0, y1)) <= 0;
}

map< point, int > nombre;
int siguienteNombre;

const int MAXN = 22 * 22;

vector<segment> segmentos;

bool coincidentes(const segment &s1, const segment &s2) {
    double x0 = s1.first.x;
    double y0 = s1.first.y;
    double x1 = s1.second.x;
    double y1 = s1.second.y;
    
    double x2 = s2.first.x;
    double y2 = s2.first.y;
    double x3 = s2.second.x;
    double y3 = s2.second.y;
    
    double t0 = (y3 - y2) * (x0 - x2) - (x3 - x2) * (y0 - y2);
    double t1 = (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0);
    double det = (y1 - y0) * (x3 - x2) - (y3 - y2) * (x1 - x0);
    if (cmp(det, 0) == 0) {
        //paralelas
        if (cmp(t0, 0) == 0 || cmp(t1, 0) == 0) {
            return (point_in_box(x0, y0,   x2, y2, x3, y3) ||
                    point_in_box(x1, y1,   x2, y2, x3, y3) ||
                    point_in_box(x2, y2,   x0, y0, x1, y1) ||
                    point_in_box(x3, y3,   x0, y0, x1, y1) );
        }
        return false;
    }
    return false;
}

segment mix(const segment &s1, const segment &s2) {
    double x0 = s1.first.x;
    double y0 = s1.first.y;
    double x1 = s1.second.x;
    double y1 = s1.second.y;
    
    double x2 = s2.first.x;
    double y2 = s2.first.y;
    double x3 = s2.second.x;
    double y3 = s2.second.y;

    if (cmp(x0, x1) != 0) { // no es vertical
        double minX = min( min(x0, x1),  min(x2, x3) );
        double maxX = max( max(x0, x1),  max(x2, x3) );
    
        point left, right;
        if (cmp(x0, minX) == 0) left = point(x0, y0);
        if (cmp(x1, minX) == 0) left = point(x1, y1);        
        if (cmp(x2, minX) == 0) left = point(x2, y2);
        if (cmp(x3, minX) == 0) left = point(x3, y3);
                
        if (cmp(x0, maxX) == 0) right = point(x0, y0);
        if (cmp(x1, maxX) == 0) right = point(x1, y1);        
        if (cmp(x2, maxX) == 0) right = point(x2, y2);
        if (cmp(x3, maxX) == 0) right = point(x3, y3);        

        return segment(left, right);
    }
    
    assert(cmp(y0, y1) != 0);
    double minY = min( min(y0, y1),  min(y2, y3) );
    double maxY = max( max(y0, y1),  max(y2, y3) );

    point left, right;
    if (cmp(y0, minY) == 0) left = point(x0, y0);
    if (cmp(y1, minY) == 0) left = point(x1, y1);        
    if (cmp(y2, minY) == 0) left = point(x2, y2);
    if (cmp(y3, minY) == 0) left = point(x3, y3);
            
    if (cmp(y0, maxY) == 0) right = point(x0, y0);
    if (cmp(y1, maxY) == 0) right = point(x1, y1);        
    if (cmp(y2, maxY) == 0) right = point(x2, y2);
    if (cmp(y3, maxY) == 0) right = point(x3, y3);        

    return segment(left, right);
    
}

bool unir(vector<segment> &s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (coincidentes(s[i], s[j])) {
                s.push_back( mix(s[i], s[j]) );
                s.erase(s.begin() + j);
                s.erase(s.begin() + i);
                return true;
            }
        }
    }
    return false;
}


double direction(double x1, double y1,  double x2, double y2,  double x3, double y3) {
    return (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1);
}

bool colineales(const point &a, const point &b, const point &c ) {
    return cmp(0, (b.x - a.x) * (c.y - a.y) - (c.x -a .x) * (b.y - a.y) ) == 0;
}


pair<bool, point> interseccion(const segment &s1, const segment &s2) {
    double x0 = s1.first.x;
    double y0 = s1.first.y;
    double x1 = s1.second.x;
    double y1 = s1.second.y;
    
    double x2 = s2.first.x;
    double y2 = s2.first.y;
    double x3 = s2.second.x;
    double y3 = s2.second.y;
    
    double t0 = (y3 - y2) * (x0 - x2) - (x3 - x2) * (y0 - y2);
    double t1 = (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0);
    double det = (y1 - y0) * (x3 - x2) - (y3 - y2) * (x1 - x0);

    if (cmp(det, 0) == 0) {
        //paralelas
        // assert(cmp(t0, 0) != 0 and cmp(t1, 0) != 0);
        return make_pair(false, point(0, 0) );
    }
    
    t0 /= det;
    t1 /= det;
    
    if (cmp(0, t0) <= 0 and cmp(t0, 1) <= 0 and cmp(0, t1) <= 0 and cmp(t1, 1) <= 0 ) {
        double x = x0 + t0 * (x1 - x0);
        double y = y0 + t0 * (y1 - y0);
        return make_pair(true, point(x, y));
    }
    return make_pair(false, point(0, 0) );
    
}
int main(){
    siguienteNombre = 1;
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        segmentos.push_back( segment(  point(x1, y1),  point(x2, y2)  ) );
    }
    while (unir(segmentos));
    n = segmentos.size();
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                const segment &s1 = segmentos[i];
                const segment &s2 = segmentos[j];
                const segment &s3 = segmentos[k];
                
                pair<bool, point> c1 = interseccion(s1, s2);
                pair<bool, point> c2 = interseccion(s1, s3);
                pair<bool, point> c3 = interseccion(s2, s3);
                
                if (!c1.first or !c2.first or !c3.first) continue;
                if (colineales(c1.second, c2.second, c3.second)) continue;
                ans++;
                
                // printf("tripleta i = %d, j = %d, k = %d\n", i, j, k);
                // printf("   si = (%lf, %lf) a (%lf, %lf)\n", s1.first.x, s1.first.y, s1.second.x, s1.second.y);
                // printf("   sj = (%lf, %lf) a (%lf, %lf)\n", s2.first.x, s2.first.y, s2.second.x, s2.second.y);
                // printf("   sk = (%lf, %lf) a (%lf, %lf)\n", s3.first.x, s3.first.y, s3.second.x, s3.second.y);                                        
            }
        }
    }
    

    printf("%d\n", ans);
    return 0;
}