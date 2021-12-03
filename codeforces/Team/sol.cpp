#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n; cin >> n;
    int ans = 0;

    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        ans += (a + b + c > 1);
    }
    cout << ans << endl;
    return 0;
}