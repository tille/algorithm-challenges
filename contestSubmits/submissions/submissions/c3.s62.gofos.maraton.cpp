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

int di[] = {0, 0, +1, -1, -1, +1, -1, +1};
int dj[] = {-1, +1, 0, 0, -1, +1, +1, -1};

int main(){
    
    int n = 0;
    cin >> n;
    string board [n];
    for(int i = 0; i < n; i++){
        string line; cin >> line;
        board[i] = line;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            //Asume it starts at pos i,j
            if (board[i][j] == '.') continue;
            char player = board[i][j];
            for (int k = 0; k < 8; k++){                
                int ni = i;
                int nj = j;
                int count = 0;
                while(board[ni][nj] == player and count < 3){
                    count++;
                    ni += di[k];
                    nj += dj[k];
                    if (ni < 0 or ni >= n or nj < 0 or nj >= n) break;
                }
                if (count == 3){
                    cout << player << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << "ongoing" << endl;
    
    
    return 0;
}