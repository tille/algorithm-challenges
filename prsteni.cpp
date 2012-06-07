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

void red(int n1, int n2){
    for( int i = 2; i <= 9; ++i ){
        while( !(n1%i) && !(n2%i) ) n1 /= i, n2 /= i;
    }
    cout << n1 << "/" << n2 << endl;
}

int main(){
    int n, ans, number;
    cin >> n;
    for( int i = 0; i < n; ++i ){
        cin >> number;
        if( !i ) ans = number;
        else red(ans,number);
    }
    return 0;
}
