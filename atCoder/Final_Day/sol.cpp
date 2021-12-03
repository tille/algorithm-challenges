#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int a, b, c;
    int n, k; cin >> n >> k;
    vi nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        nums[i] = a + b + c;
    }

    vi nums2 = nums;
    sort(nums2.begin(), nums2.end());

    for (auto &x : nums) {
        auto ans = n - (upper_bound(nums2.begin(), nums2.end(), x + 300) - nums2.begin());
        ans++;
        cout << (ans <= k ? "Yes" : "No") << endl;
    }
    return 0;
}