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
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); \
                           x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define INPUT_FILE "rocket"

int main(){
    
    freopen(INPUT_FILE ".in", "r", stdin); // Read from file
    cin >> cases;
    while(cases--){
        int n, contW, gasW, force, gasBurn, totalW, netForce;
        cin >> n ;
        int conteiner[n][4];
        for(int i =0; i < n; i++){
            for(int j = 0; i < 4; i++){
                cin >> info;
                conteiner[i][j] = info;
                if(j == 0 || j == 1){
                    totalW += conteiner[i][j];
                }
            }
        }
        for(int i = 0; i < n; i++){
        
        }
    }
    
    

    return 0;
}
