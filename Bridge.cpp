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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

vector<int> v1;

void simulation(){
    int temp1,temp2;
    temp1 = temp2 = 0;

    while(v1.size()){
        if( v1.size() == 1 ){ printf("%d\n",v1[0]); break; }
        else if( v1.size() == 2 ){ printf("%d %d\n",v1[0],v1[1]); break; }
        else if( v1.size() == 3 ){ printf("%d %d\n%d\n%d %d\n",v1[0],v1[2],v1[0],v1[0],v1[1]); break; }
        else{
            temp1 = (v1[0]+v1[v1.size()-1]+(v1[1]*2));
            temp2 = (v1[v1.size()-2]+v1[v1.size()-1]+(v1[0]*2));
            if( temp1 < temp2 ){
                printf("%d %d\n%d\n%d %d\n%d\n",v1[0],v1[1],v1[0],v1[v1.size()-2],v1[v1.size()-1],v1[1]);
            }else{
                printf("%d %d\n%d\n%d %d\n%d\n",v1[0],v1[v1.size()-1],v1[0],v1[0],v1[v1.size()-2],v1[0]);
            }
            v1.erase(v1.end()-1);
            v1.erase(v1.end()-1);
        }
    }
}

int calc(){
    vector<int> cpy1;
    cpy1.clear();
    int result = 0;
    cpy1 = v1;

    while(cpy1.size()){
        if( cpy1.size() == 1 ) return result += cpy1[0];
        else if( cpy1.size() == 2 ) return result += max(cpy1[0],cpy1[1]);
        else if( cpy1.size() == 3 ) return result += (cpy1[0]+cpy1[1]+cpy1[2]);
        else{
            result += min( (cpy1[0]+cpy1[cpy1.size()-1]+(cpy1[1]*2)),(cpy1[cpy1.size()-2]+cpy1[cpy1.size()-1]+(cpy1[0]*2)) );
            cpy1.erase(cpy1.end()-1);
            cpy1.erase(cpy1.end()-1);
        }
    }
    return result;
}

int main(){
    int t,n,num;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);

    for( int j = 0; j < t; ++j ){
        scanf("%d",&n), v1.clear();
        for( int i = 0; i<n; ++i ){
            scanf("%d",&num);
            v1.push_back(num);
        }
        sort(v1.begin(),v1.end());
        printf("%d\n",calc());
        simulation();
        if( j != (t-1) ) printf("\n");
    }
    return 0;
}
