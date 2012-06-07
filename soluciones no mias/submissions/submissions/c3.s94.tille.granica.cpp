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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

ll numbers[100+5];

int main(){
    int n,salir,salir2;
    cin >> n;
    for( int i = 0; i < n; ++i ) cin >> numbers[i];
    salir2 = 1;
    for( ll j = 2; j < 1000000000 && salir2; ++j ){
        if( j > numbers[0] ) salir2 = 0;
        ll temp = numbers[0]%j;
        salir = 1;
        for( int i = 1; i < n && salir && salir2; ++i ){
            if( j > numbers[i] ) salir2 = 0;
            if( (numbers[i]%j) != temp ) salir = 0;
        }
        if( salir && salir2 ) cout << j << " ";
    }
    return 0;
}
