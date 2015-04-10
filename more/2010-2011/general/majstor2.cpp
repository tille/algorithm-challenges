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

string friends[50+5];
string s;
int m,n;

int winner(char a, char b){
    if( a == 'R' && b == 'S' ) return 2;
    else if( a == 'P' && b == 'R' ) return 2;
    else if( a == 'S' && b == 'P' ) return 2;
    else if( a == b ) return 1;
    else return 0;
}

int eval(int h, char a){
    int cont = 0;
    for( int i = 0; i < m; ++i){
        cont += winner(a,friends[i][h]);
    }
    return cont;
}

void solve(){
    int result = 0, ans = 0;
    for( int i = 0; i < s.size(); ++i ) result += eval(i,s[i]);
    for( int i = 0; i < s.size(); ++i ) ans += (max( eval(i,'P'),max(eval(i,'S'),eval(i,'R')) ));
    printf("%d\n%d",result,ans);
}

int main(){
    while( cin >> n ){
        cin >> s;
        cin >> m;
        for( int i = 0; i < m; ++i ){
            cin >> friends[i];
        }
        solve();
    }
    return 0;
}
