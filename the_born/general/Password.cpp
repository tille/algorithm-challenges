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

    template <class T> int toInt(const T &x)
    { stringstream s; s << x; int r; s >> r; return r; }

    #define For(i, a, b) for (int i=(a); i<(b); ++i)
    #define D(x) cout << #x " es " << (x) << endl

    const double EPS = 1e-9;
    int cmp(double x, double y, double tol = EPS)
    { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

    string s;

    void kmp( int n ){
        vector<int> border(n);
        vector<int> rank(n);
        vector<int> q;

        border[0] = 0;
        for( int i = 1; i < n; ++i ){
            border[i] = border[i-1];
            while( border[i] > 0 && s[i]!=s[border[i]]) border[i] = border[border[i]-1];
            if( s[i] == s[border[i]] ) border[i]++;
        }

        for (int i = 1; i < n - 1; ++i) rank[border[i]] = true;
        //cout << rank[border[1]] << " " << rank[border[2]] << endl;


        //By Andres Mejia beatifull solution
        int k = border[n - 1];
        while (k > 0) {
            //cout << "paso por aki con k: " << k << " rank[k]: " << rank[k] << endl;
            if (rank[k]) { // found
                cout << s.substr(0, k) << endl;
                break;
            }
            k = border[k - 1];
        }
        if (k == 0) {
            puts("Just a legend");
        }
        ///////////////////////////////////////

    }

    int main(){
        while( cin >> s ){
            kmp(s.size());
        }
        return 0;
    }
