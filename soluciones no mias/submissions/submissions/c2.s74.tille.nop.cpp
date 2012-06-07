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
    int cont = 1, acum = 0;
    string s; cin >> s;
    for( int i = 1; i < s.size(); ++i ){
        if( isupper(s[i]) ){
            if( cont%4 != 0 ) acum += (((int(cont/4)*4)+4)-cont);
            cont = 1;
        }else cont++;
    }
    cout << acum << endl;
    return 0;
}
