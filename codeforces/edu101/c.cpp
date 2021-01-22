#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        
        int mn = a[0];
        int mx = a[0];

        bool ok = false;
        for (int i = 1; i < a.size() && !ok; ++i) {
            mn = max(mn - k + 1, a[i]);
            mx = min(mx + k - 1, a[i] + k - 1);
            if (mn > mx)
                ok = true;
        }
        if (a.back() < mn || a.back() > mx)
            ok = true;
        
        string ans = ok ? "no" : "yes";
        cout << ans << endl;
    }
}