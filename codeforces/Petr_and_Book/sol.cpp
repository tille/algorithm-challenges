#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>

int main() {
    int n; cin >> n;

    vi arr(7), prefixSum(7);
    for (auto &x : arr) cin >> x;

    prefixSum[0] = arr[0];
    for (int i = 1; i < 7; i++) prefixSum[i] = prefixSum[i - 1] + arr[i];

    while (true) {
        auto it = lower_bound(prefixSum.begin(), prefixSum.end(), n);
        if (it != prefixSum.end()) {
            cout << it - prefixSum.begin() + 1 << endl;
            return 0;
        }
        n -= prefixSum.back();
    }

    return 0;
}