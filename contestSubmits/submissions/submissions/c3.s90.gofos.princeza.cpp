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


struct compareDouble {
  bool operator()(double a, double b) {
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

map<double, set<double>, compareDouble> XgivenY;
map<double, set<double>, compareDouble> YgivenX;

map<point, pair<int, int> > original;


int P;

const double rotator = sqrt(2) / 2;

void erase(const point &p) {
    XgivenY[p.y].erase( p.x );
    YgivenX[p.x].erase( p.y );
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
    }

    set<double>::iterator where;
        
//    D(jumps);
    for(int i = 0; i < jumps; i++){
        // printf("Before move i = %d (%c):  ", i, moves[i]);
        // pair<int, int> k = original[current];
        // printf("Current = (%d, %d)\n", k.first, k.second);
        
        
        if(moves[i] == 'A'){
            const set<double> &p = YgivenX[ current.x ];
            where = p.upper_bound( current.y );
            if (where == p.end()) continue;
            point old = current;
            current = point(current.x, *where);
            erase(old);
        }
        if(moves[i] == 'B'){
            const set<double> &p = XgivenY[ current.y ];
            where = p.upper_bound( current.x );
            if (where == p.end()) continue;
            point old = current;
            current = point(*where, current.y);
            erase(old);
        }
        if(moves[i] == 'C'){
            const set<double> &p = XgivenY[ current.y ];   
            where = p.lower_bound( current.x );
            if (where == p.begin()) continue;
            where--;
            point old = current;
            current = point(*where, current.y);
            erase(old);
        }
        if(moves[i] == 'D'){
            const set<double> &p = YgivenX[ current.x ];   
            where = p.lower_bound( current.y );
            if (where == p.begin()) continue;
            where--;
            point old = current;
            current = point(current.x, *where);
            erase(old);
        }
    }
    
    pair<int, int> ans = original[current];
    printf("%d %d\n", ans.first, ans.second);
    
    return 0;
}