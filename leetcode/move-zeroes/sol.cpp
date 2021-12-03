#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &nums) {
    int p1 = 0, p2 = 0;
    int sz = nums.size();

    while (p1 < sz && p2 < sz) {
        while (p1 < sz && nums[p1]) p1++;
        while (p2 < sz && !nums[p2] || p2 < p1) p2++;

        if (p1 < sz && p2 < sz && p2 > p1) {
            swap(nums[p1], nums[p2]);
            p1++, p2++;
        }
    }
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);

    for (auto &x:nums) cin >> x;

    solve(nums);

    for (auto &x:nums) cout << x << " ";
    cout << endl;

    return 0;
}