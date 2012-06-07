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

int arr[300];

int main(){
    int temp = -1, cont = 0;
    string s;
    cin >> s;
    for( int i = 0; i < s.size(); ++i ){
        if( isupper(s[i]) ){
            temp = int(s[i]);
            if( !arr[temp] ) arr[temp]++;
        }else arr[temp]++;
    }
    for( int i = 0; i < 298; ++i ){
        if( arr[i] != 0 ){
            if( arr[i] > 4 ) arr[i] = 4;
            cont += (4-arr[i]);
        }
    }
    cout << cont << endl;
    return 0;
}
