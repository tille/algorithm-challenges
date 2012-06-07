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
#define For(i, a, b) for (int i=(a); i<(b); ++i)

long long rev (long long n) {
    long long x = 0,y = n;
    while(y){
        x *= 10;
        x += y%10;
        y /= 10;
    }
    return x;
}

int main(){

    long long r,t,n;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        r = 1;
        n = n+rev(n);
        while(n-rev(n)){
            n = n+rev(n);
            ++r;
        }
        printf("%lld %lld\n",r,n);
    }
    return 0;
}
