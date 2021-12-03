#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a, b, c;

    while (n--) {
        cin >> a >> b >> c; c++;
        if (a > b) swap(a, b);

        string ans = (b/double(a) <= c)  ? "YES" : "NO";
        cout << ans << endl;
    }
    return 0;
}