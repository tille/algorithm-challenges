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

typedef unsigned long long ll;

int main(){
    ll n, temp = 1;
    cin >> n;
    for( int i = 0; i < n; ++i ) temp *= 4;
    cout << (int(sqrt(temp))+1)*(int(sqrt(temp))+1) << endl;
    return 0;
}
