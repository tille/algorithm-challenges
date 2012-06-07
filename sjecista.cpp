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

int result[110];

int calc( int n ) {
    int cant = n-3, sup = n-3, inf = 1, result = 0;

    for( int i = 0; i < int(cant/2); ++i ){
        result += ((sup*inf)*2);
        sup--; inf++;
    }
    if( !(n%2) ) result += (sup*inf);
    return result;
}

int main(){
    int n;
    while( cin >> n ){
        cout << (calc(n)*n)/4 << endl;
    }
    return 0;
}
