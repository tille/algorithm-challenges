#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>

int main() {
    int n; cin >> n;

    vi arr(n);
    for (auto &x : arr) cin >> x;

    int ans = 1<<30, x, y;
    for (int i = 0; i < n; ++i) {
        int val = abs(arr[i] - arr[(i + 1) % n]);
        if (val < ans) {
            x = i + 1;
            y = (i + 1) % n; y++;
            ans = val;
        }
    }
    cout << x << " " << y << endl;

    return 0;
}