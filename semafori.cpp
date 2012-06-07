using namespace std;
#include <cstdio>

typedef long long ll;

int main(){
    int n,l,d,r,g,p = 0, result = 0;
    cin >> n >> l;
    for( int i = 0; i < n; ++i ){
        cin >> d >> r >> g;
        int dist = result+(d-p);
        result = (dist%(r+g) < r)?dist+(r-(dist%(r+g))):dist;
        p = d;
    }
    cout << (result+(l-p)) << endl;
    return 0;
}
