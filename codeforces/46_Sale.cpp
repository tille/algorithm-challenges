#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n, m;
    cin >> n >> m;

    vi sets(n);

    for (auto &x : sets) cin >> x;
    sort(sets.begin(), sets.end());

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (sets[i] < 0) ans += sets[i];
    }
    cout << ans*(-1) << endl;
    return 0;
}