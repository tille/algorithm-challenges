#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n, a,b,c;
    cin >> n; vi sol(3, 0);


    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        sol[0] += a; sol[1] += b; sol[2] += c;
    }
    if (!sol[0] && !sol[1] && !sol[2]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}