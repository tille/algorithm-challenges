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

int a[30], b[30], n,t,temp,acum;

int main(){
    for(int i = 1; i <= 28; ++i){
        a[i] = i;
    }
    for(int j = 28; j <= 28+28; ++j){
        b[j] = j;
    }

    int *ap, *bp;
    ap = a;
    bp = b;

    cout << *a << endl;
//    *a = bp;
    *b = *ap;
    cout << a[1] << endl;

    return 0;
}
