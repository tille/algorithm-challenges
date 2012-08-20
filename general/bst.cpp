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

// La misma idea propuesta en las soluciones del juez
// la verdad no se me ocurrio nada mas :(

int main(){
    long long n, cosa = 0;
    int result, num;
    cin >> n;
    map<int,int> ans;
    map<int,int>::iterator it;
    for( int i = 0; i < n; ++i ){
        cin >> num;
        it = ans.lower_bound(num); result = 0;
        if( it != ans.end() ) result = max(result,(it)->second+1);
        if( it != ans.begin() ) result = max(result,(--it)->second+1);

        ans[num] = result; cosa += result;
        cout << cosa << endl;
    }
    return 0;
}
