#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

typedef long long ll;

template <class T> string toStr( const T &x )
{ stringstream s; s << x; return s.str(); }

template <class T> long long toInt( const T &x )
{ stringstream s; s << x; long long r; s >> r; return r; }

int main(){
    ll a,b;
    cin >> a >> b;
    cout << a+b;
    return 0;
}
