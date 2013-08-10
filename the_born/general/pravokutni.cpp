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

unsigned long long points[1500+5][2];

int main(){
    freopen("caso.in","r",stdin);
    int n;
    while( cin >> n ){
        for( int i = 1; i <= n; ++i ){
            scanf("%lli %lli",&points[i][0],&points[i][1]);
        }
        int cont = 0;
        for( int i = 1; i <= n; ++i ){
            for( int j = i+1; j <= n; ++j ){
                for( int k = j+1; k <= n; ++k ){
                    unsigned long long temp1 = (points[i][0]-points[j][0])*(points[i][0]-points[j][0]) + ((points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
                    unsigned long long temp2 = (points[i][0]-points[k][0])*(points[i][0]-points[k][0]) + ((points[i][1]-points[k][1])*(points[i][1]-points[k][1]));
                    unsigned long long temp3 = (points[k][0]-points[j][0])*(points[k][0]-points[j][0]) + ((points[k][1]-points[j][1])*(points[k][1]-points[j][1]));

                    if( temp1+temp2==temp3 || temp2+temp3==temp1 || temp3+temp1==temp2) cont++;
                }
            }
        }
        printf("%d\n",cont);
    }
    return 0;
}
