#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        string ans = (pow(2, log2(n)) == n) ? "no" : "yes";
        cout << ans << endl;
    }
    return 0;
}