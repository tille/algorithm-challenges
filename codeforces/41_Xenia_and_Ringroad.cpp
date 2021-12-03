#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int n, k, num;
    cin >> n >> k;

    int cur = 1;
    ll ans = 0;
    while (k--) {
        cin >> num;
        if (num >= cur) ans += (num - cur);
        else ans += (n - abs(num - cur));
        cur = num;
    }
    cout << ans << endl;
    return 0;
}