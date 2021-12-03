#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>

int main() {
    int n; cin >> n;

    vi nums(12);
    for (auto &x : nums) cin >> x;

    sort(nums.begin(), nums.end(), greater<int>());

    int acum = 0, i = 0;
    while (acum < n) {
        acum += nums[i++];
        if (i > 11) break;
    }

    cout << (acum < n ? -1 : i) << endl;
    return 0;
}