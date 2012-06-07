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

bool all_eq(char a,char b,char c) {
 return a==b and b == c and a == c;   
}

int main () {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int n;
    cin>>n;
    string mat [n];
    for (int i = 0; i < n  ; ++i) {
             cin>>mat[i];
    }
    
    for (int i = 0; i < n-2; ++i) {
        for (int j = 0; j < n-2; ++j) {
            if (mat[i][j] != '.')
            if (all_eq(mat[i][j],mat[i+1][j+1],mat[i+2][j+2]))
                {
                  cout<<mat[i][j]<<endl;
                 return 0;  
                }
        }   
    }
    for (int i = 0; i < n-2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] != '.')
            if (all_eq(mat[i][j],mat[i+1][j],mat[i+2][j]))
                {
                  cout<<mat[i][j]<<endl;
                 return 0;  
                }
        }   
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-2; ++j) {
            if (mat[i][j] != '.')
            if (all_eq(mat[i][j],mat[i][j+1],mat[i][j+2]))
                {
                  cout<<mat[i][j]<<endl;
                 return 0;  
                }
        }   
    }
    
    for (int i = 0; i < n-2; ++i) {
        for (int j = 2; j < n; ++j) {
            if (mat[i][j] != '.') {
                if (all_eq(mat[i][j],mat[i+1][j-1],mat[i+2][j-2]))
              
              {
                 cout<<mat[i][j]<<endl;
                 return 0;   
                }   
            }   
        }   
    }
    
    cout<<"ongoing"<<endl;
    return 0;
}
