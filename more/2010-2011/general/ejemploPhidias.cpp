
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cassert>

#pragma comment(linker, "/STACK:16777216")

#define mset(block,value) memset(block,value,sizeof(block))
#define fo(i,begin,end) for(int i=begin; i<end; i++)
#define fosz(i,s,x) for(int i=s; i<x.size(); i++)
#define foreach(i,x) fosz(i,0,x)
#define debug(x) cerr<<(#x)<<" = "<<(x)<<endl
#define adebug(x,n) fo(i,0,n) cerr<<(#x)<<"["<<i<<"] = "<<x[i]<<endl
#define vdebug(x) foreach(i,x) cerr<<(#x)<<"["<<i<<"] = "<<x[i]<<endl
#define showv(v) foreach(i,v) cout<<v[i]<<" "; cout<<endl
#define ALL(v) v.begin(), v.end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<i64> v64;
typedef vector<i64> vv64;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const double pi=2*acos(0.0);
const int inf=1e9;


int main()
{
        int tc;
        cin>>tc;
        fo(i,0,tc)
        {
                int n,W,H;
                cin>>W>>H>>n;
                map<pii,bool> needs;

                fo(i,0,n)
                {
                        int w,h;
                        cin>>w>>h;
                        needs[pii(h,w)] = true;
                }

                vvi dp(H+1,vi(W+1,0));

                for(int ww=1; ww<=W; ww++)
                        for(int hh=1; hh<=H; hh++)
                        {
                                if(needs.count(pii(hh,ww)))
                                {
                                        dp[hh][ww] = 0;
                                        goto cont;
                                }
                                int ans = hh*ww;

                                fo(i,1,ww)
                                        ans = min(ans, dp[hh][i]+dp[hh][ww-i]);

                                fo(i,1,hh)
                                        ans = min(ans, dp[i][ww]+dp[hh-i][ww]);

                                dp[hh][ww] = ans;

                                cont: ;
                        }

                for( int i = 0; i <= H; ++i ){
            for( int j = 0;  j<= W; ++j ){

        cout << dp[i][j] << " ";
            }
            cout << endl;
                }

        }
    return 0;
}
