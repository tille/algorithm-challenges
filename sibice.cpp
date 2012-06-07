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
    int t, n, m, number;
    cin >> t >> n >> m;
    int ans = floor(sqrt(((n*n)+(m*m))));
    for( int i = 0; i < t; ++i ){
        cin >> number;
        cout << (( number <= ans )?"DA":"NE") << endl;
    }
    return 0;
}
