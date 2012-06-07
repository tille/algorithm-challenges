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
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int n;
    cin>>n;
    int arr [n];
    for (int i = 0; i < n; ++i)
    cin>>arr[i];
    sort(arr,arr+n);
    bool has = false;
    
    for (int i = 2; i <= arr[1]; ++i) {
        int beg = arr[0]%i;
        bool is = true;
        for (int j = 1; j < n; ++j) {
            if (arr[j]%i != beg)
                {is = false;break;}
        }
        if (is){
            if (has)
            cout<<' ';
            else
            has = true;
            cout<<i;
        }
    }
    cout<<endl;
    
    return 0;
}
