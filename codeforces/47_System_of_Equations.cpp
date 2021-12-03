#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000;

int main() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int a = 0; a*a <= n; ++a) {
        for (int b = 0; b*b <= m; ++b) {
            if ((a*a) + b == n and a + (b*b) == m) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}