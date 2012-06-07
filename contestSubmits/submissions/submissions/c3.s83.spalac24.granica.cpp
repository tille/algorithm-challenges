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
    
    int n;
    scanf("%d",&n);
    int arr [n];
    for (int i = 0; i < n; ++i)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    bool has = false;
    int beg;
    bool is;
    int lim = arr[1]-arr[0];
    lim = max(arr[0],lim);
    for (int i = 2; i <= lim; ++i) {
        beg = arr[0]%i;
        is = true;
        for (int j = 1; j < n; ++j) {
            if (arr[j]%i != beg)
                {is = false;break;}
        }
        if (is){
            if (has)
            putchar(' ');
            else
            has = true;
            printf("%d",i);
        }
    }
    printf("\n");
    
    return 0;
}
