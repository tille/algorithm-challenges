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

struct semaforo {
    ll d,r,g;
    semaforo(){}
};

bool func (semaforo a, semaforo b) {
    return (a.d < b.d);   
}

int main () {
    ll n,l;
    cin>>n>>l;
    semaforo arr [n];
    for (int i = 0; i< n; ++i) {
        cin>>arr[i].d>>arr[i].r>>arr[i].g;   
    }
    sort(arr,arr+n, func);
    
    
    
    ll tot = arr[0].d;
    if ((tot%(arr[0].r+arr[0].g))<arr[0].r){
        tot += arr[0].r-tot%(arr[0].r+arr[0].g);
    }
    //cout<<"para el 0 semaforo lleva "<<tot<<endl;
    for (int i = 1; i < n; ++i) {
         tot += arr[i].d-arr[i-1].d;
         
       //  cout<<"para el "<<i<<" semaforo lleva "<<tot<<endl; 
         if ((tot%(arr[i].r+arr[i].g))<arr[i].r){
                tot += arr[i].r-(tot%(arr[i].r+arr[i].g));
         } 
        // cout<<"para el "<<i<<" semaforo lleva "<<tot<<endl; 
    }
    tot += l - arr[n-1].d;
    cout<<tot<<endl;
    return 0;
}
