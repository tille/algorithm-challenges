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

int main(){
    string s;
    cin >> s;
    for( int i = 0; i < s.size(); ++i )
        if( isupper(s[i]) ) cout << s[i];
    cout << endl;
    return 0;
}
