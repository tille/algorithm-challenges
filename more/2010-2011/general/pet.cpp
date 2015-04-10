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
    int mayor = 0, player, a, cont;
    for( int i = 0; i < 5; ++i ){
        cont = 0;
        for( int j = 0; j < 4; ++j){
            cin >> a;
            cont += a;
        }
        if( cont > mayor ){
            player = i+1;
            mayor = cont;
        }
    }
    printf("%d %d",player, mayor);
    return 0;
}
