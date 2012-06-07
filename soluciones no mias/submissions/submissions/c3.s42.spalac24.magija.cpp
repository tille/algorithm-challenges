#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include <iomanip>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

typedef unsigned long long int ul;
typedef long long ll;

const double EPS = 1e-9;

template <class T> string toStr(const T &x){
stringstream s; s << x; return s.str();
}

template <class T> int toInt(const T &x){
stringstream s; s << x; int r; s >> r; return r;
}


int main () {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int r,c;
    cin>>r>>c;
    char mat [r][c];
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin>>mat[i][j];
    int a,b;
    char mat2 [2*r+2][2*c+2];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            mat2[i][2*c-j-1]=mat[i][j];
            mat2[i][j]=mat[i][j];
            mat2[2*r-1-i][j] = mat[i][j];
            mat2[2*r-i-1][2*c-j-1] = mat[i][j];  
        }   
    }
    cin>>a>>b;
    mat2[a-1][b-1] = mat2[a-1][b-1]=='#'?'.':'#';
    for (int i = 0; i < 2*r; ++i){
        for (int j = 0; j < 2*c; ++j) {
            cout<<mat2[i][j];   
        }
        cout<<endl;
    }
    
    return 0;
}
