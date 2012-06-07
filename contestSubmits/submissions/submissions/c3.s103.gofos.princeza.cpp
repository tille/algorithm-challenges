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

const double EPS = 1e-7;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
////////////////////////// Solution starts below. //////////////////////////////


struct compareDouble {
  bool operator()(double a, double b) const {
      return cmp(a, b) < 0;
  }
};

struct point {
    double x, y;
    point(double x, double y)  : x(x), y(y) {}
    point(){}
    bool operator < (const point &p) const {
        if (cmp(x, p.x) != 0) return cmp(x, p.x) < 0;
        return cmp(y, p.y) < 0;
    }
};

typedef set<double, compareDouble> doubleset;
map<double, doubleset, compareDouble> XgivenY;
map<double, doubleset, compareDouble> YgivenX;

map<point, pair<int, int> > original;


int P;

const double rotator = sqrt(2) / 2;

void erase(const point &p) {
    
    // printf("Erasing (%lf %lf) (originally %d, %d)\n", p.x, p.y, original[p].first, original[p].second);
    // 
    // printf("Before erasing:\n");
    // printf("XgivenY.size = %d\n", XgivenY.size());
    // foreach(pp, XgivenY) {
    //     foreach(s, pp->second) {
    //         printf("XgivenY contains (%lf, %lf)\n", *s, pp->first);
    //     }
    // }
    // printf("YgivenX.size = %d\n", YgivenX.size());
    // foreach(pp, YgivenX) {
    //     foreach(s, pp->second) {
    //         printf("YgivenX contains (%lf, %lf)\n", pp->first, *s);
    //     }
    // }
    
    doubleset::iterator k;
    
    k = XgivenY[p.y].find( p.x );
    //assert(k != XgivenY[p.y].end() );
    if (k != XgivenY[p.y].end() ) XgivenY[p.y].erase(k);
    
    k = YgivenX[p.x].find( p.y );
    //assert(k != YgivenX[p.x].end() );
    if (k != YgivenX[p.x].end() ) YgivenX[p.x].erase(k);
    
}

double print(set<double> p) {
    foreach(pp, p) cout << *pp << " ";
    puts("");
}

int main(){
    
    int leaves;
    int jumps;
    cin >> leaves >> jumps;
    string moves; cin >> moves;
    point current;
    for(int j = 0; j < leaves; j++){
        int a, b; cin >> a >> b;
        
        double x = a * rotator - b * rotator;
        double y = a * rotator + b * rotator;
        
        original[point(x, y)] = make_pair(a, b);
        
        XgivenY[y].insert(x);
        YgivenX[x].insert(y);
        
        if (j == 0) current = point(x, y);
        
        //printf("%d %d se vuelve %lf %lf\n", a, b, x, y);
    }

    doubleset::iterator where;
        
//    D(jumps);
    for(int i = 0; i < jumps; i++){
        // printf("Before move i = %d (%c):  ", i, moves[i]);
        // pair<int, int> k = original[current];
        // printf("Current = (%d, %d)\n", k.first, k.second);
        
        
        if(moves[i] == 'A'){
            const doubleset &p = YgivenX[ current.x ];
            where = p.upper_bound( current.y );
            if (where == p.end()) continue;
            point old = current;
            current = point(current.x, *where);
            erase(old);
        }
        if(moves[i] == 'B'){
            const doubleset &p = XgivenY[ current.y ];
            where = p.upper_bound( current.x );
            if (where == p.end()) continue;
            point old = current;
            current = point(*where, current.y);
            erase(old);
        }
        if(moves[i] == 'C'){
            const doubleset &p = XgivenY[ current.y ];   
            where = p.lower_bound( current.x );
            if (where == p.begin()) continue;
            where--;
            point old = current;
            current = point(*where, current.y);
            erase(old);
        }
        if(moves[i] == 'D'){
            const doubleset &p = YgivenX[ current.x ];   
            where = p.lower_bound( current.y );
            if (where == p.begin()) continue;
            where--;
            point old = current;
            current = point(current.x, *where);
            erase(old);
        }
    }
    
    assert(original.count(current) > 0);
    pair<int, int> ans = original[current];
    printf("%d %d\n", ans.first, ans.second);
    
    return 0;
}