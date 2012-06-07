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


map<int, set<int> > XgivenY;
map<int, set<int> > YgivenX;

int P;

void erase(const pair<int, int> &p) {
    set<int>::iterator k;
    
    k = XgivenY[p.second].find( p.first );
    assert(k != XgivenY[p.second].end() );
    XgivenY[p.second].erase(k);
    
    k = YgivenX[p.first].find( p.second );
    assert(k != YgivenX[p.first].end() );
    YgivenX[p.first].erase(k);
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
    pair<int, int> current;
    for(int j = 0; j < leaves; j++){
        int a, b; cin >> a >> b;
        
        int x = a + b;
        int y = a - b;
        
        XgivenY[y].insert(x);
        YgivenX[x].insert(y);
        
        if (j == 0) current = make_pair(x, y);
        
        //printf("(%d %d) se vuelve (%d, %d)\n", a, b, x, y);
    }

    set<int>::iterator where;
        
//    D(jumps);
    for(int i = 0; i < jumps; i++){
        // printf("Before move i = %d (%c):  ", i, moves[i]);
        // pair<int, int> k = original[current];
        // printf("Current = (%d, %d)\n", k.first, k.second);
        //printf("Estoy en (%d, %d) y hago un movimiento %c\n", current.first, current.second, moves[i]);
        
        if(moves[i] == 'B'){
            const set<int> &p = YgivenX[ current.first ];
            where = p.upper_bound( current.second );
            if (where == p.end()) continue;
            pair<int, int> old = current;
            current = make_pair(current.first, *where);
            erase(old);
        }
        if(moves[i] == 'A'){
            const set<int> &p = XgivenY[ current.second ];
            where = p.upper_bound( current.first );
            if (where == p.end()) continue;
            pair<int, int> old = current;
            current = make_pair(*where, current.second);
            erase(old);
        }
        if(moves[i] == 'D'){
            const set<int> &p = XgivenY[ current.second ];   
            where = p.lower_bound( current.first );
            if (where == p.begin()) continue;
            where--;
            pair<int, int> old = current;
            current = make_pair(*where, current.second);
            erase(old);
        }
        if(moves[i] == 'C'){
            const set<int> &p = YgivenX[ current.first ];   
            where = p.lower_bound( current.second );
            if (where == p.begin()) continue;
            where--;
            pair<int, int> old = current;
            current = make_pair(current.first, *where);
            erase(old);
        }
    }
    
    pair<int, int> ans = make_pair(  (current.first + current.second) / 2, (current.first - current.second) / 2 );
    printf("%d %d\n", ans.first, ans.second);
    
    return 0;
}