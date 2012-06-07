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

int a[105], n;

bool check(int m) {
    int module = a[0]%m;
    for (int i = 0; i < n; ++i) {
        if (a[i] % m != module) return false;
    }
    return true;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a,a+n);
    int smallest = a[1]-a[0];

    for(int d = 1; d * d <= smallest; ++d) {
        if(smallest % d == 0) {
            if( check(d) && d!=1 ) printf("%d ",d);
            if( check(smallest/d) && int(smallest/d)!=d ) printf("%d ",(smallest/d));
        }
    }
    return 0;
}
