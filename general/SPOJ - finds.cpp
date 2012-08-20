#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;

string p, text;
bool tales;

vector<int> preKmp( int len ){
    vector<int> b;
    int i = 0, j = -1;
    b.push_back( j );
    while( i<p.size() ){
        while( j>=0 && p[i] != p[j] ) j = b[j];
        i++; j++;
        b.push_back( j );
    }
    return b;
}

int main(){
    string salir = "*";
    int len;
    while( cin >> p && p.compare(salir) != 0 ){
        len = p.size();
        vector<int> a = preKmp( len );
        if( a[len]>0 && len % (len-a[len]) == 0 ) cout << len/(len-a[len]) << endl;
        else cout << 1 << endl;
    }
    return 0;
}
