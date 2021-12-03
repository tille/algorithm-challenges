#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, sz, ans = 0;
    cin >> a >> b >> c >> d >> sz;

    for (int i = 1; i <= sz; ++i) {
        for (auto x : {a, b, c, d}) {
            if (i % x == 0) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}