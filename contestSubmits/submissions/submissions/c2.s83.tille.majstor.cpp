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
int mayores[50+5];
string s;
char vals[] = {'R','P','S'};

int winner(char a, char b){
    if( a == 'R' && b == 'S' ) return 2;
    else if( a == 'P' && b == 'R' ) return 2;
    else if( a == 'S' && b == 'P' ) return 2;
    else if( a == b ) return 1;
    else return 0;
}

void change(int k, int n, int i){
    if( k == int('S') ){
        if( n == 0 ) s[i] = 'S';
        if( n == 1 ) s[i] = 'P';
        if( n == 2 ) s[i] = 'R';
    }else if( k == int('P') ){
        if( n == 0 ) s[i] = 'P';
        if( n == 1 ) s[i] = 'S';
        if( n == 2 ) s[i] = 'R';
    }else if( k == int('R') ){
        if( n == 0 ) s[i] = 'R';
        if( n == 1 ) s[i] = 'P';
        if( n == 2 ) s[i] = 'S';
    }
}

int solve( int f){
    int yeah = 0, result = 0;
    for( int i = 0; i < s.size(); ++i ){
        int temp = int(s[i]);
        for( int cosa = 0; cosa < 3; ++cosa ){
            change(temp,cosa,i);
            int cont = 0;
            for( int j = 0; j < f; ++j ){
                if( winner( s[i],friends[j][i] ) ){
                    cont += winner( s[i],friends[j][i] );
                }
            }
            if( !cosa ){ result += cont;  }
            else mayores[i] = max(mayores[i], cont);
        }
    }
    for( int i = 0; i < s.size(); ++i ) yeah += mayores[i];
    printf("%d\n%d",result,yeah);
}

int main(){
    int n,f;
    cin >> n >> s >> f;
    for( int i = 0; i < f; ++i ){
        cin >> friends[i];
    }
    solve(f);

    return 0;
}
