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

typedef long long ll;

int main(){
    int n, m, zr, zc;
    string ans;
    char c;
    cin >> n >> m >> zr >> zc;
    for( int i = 0; i < n; ++i ){
        ans = "";
        for( int j = 0; j < m; ++j ){
            cin >> c;
            for( int k = 0; k < zc; ++k ) ans = ans + c;
        }
        for( int k = 0; k < zr; ++k ) cout << ans << endl;
    }
    return 0;
}
