#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll n , k, cantEven, cantOdds;
    cin >> n >> k;

    cantOdds = cantEven = n / 2;
    if (n&1) cantOdds++;

    if (k > cantOdds) {
        k -= cantOdds;
        cout << 2*k << endl;
    } else {
        cout << (2*k)-1 << endl;
    }
    return 0;
}