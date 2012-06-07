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

char v[] = {'a','e','i','o','u'};

int main(){
    string s, result = "";
    getline(cin,s);
    for( int i = 0; i < s.size(); ++i ){
        result = result + s[i];
        for( int j = 0; j < 5; ++j ) if( s[i] == v[j] ) i+=2;
    }
    cout << result << endl;
    return 0;
}
