#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include <iomanip>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

typedef unsigned long long int ul;
typedef long long ll;

const double EPS = 1e-9;

template <class T> string toStr(const T &x){
stringstream s; s << x; return s.str();
}

template <class T> int toInt(const T &x){
stringstream s; s << x; int r; s >> r; return r;
}


int main () {

    int A, B, C, a1, a2, b1, b2, c1, c2, tot = 0, sum = 0;
    cin >> A >> B >> C >> a1 >> a2 >> b1 >> b2 >> c1 >>c2;
    for (int i = 1; i <= 100; ++i) {
           sum = (i>=a1 && i < a2)+(i >= b1 && i < b2) + (i >= c1 && i < c2);
           tot += ( sum == 1 )?A:( sum == 2 )?B:C;
    }
    cout<<tot<<endl;

    return 0;
}
