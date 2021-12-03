#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

vi solve(vi &nums, int target) {
    int p1 = 0, p2 = nums.size() - 1;
    while (p1 < p2) {
        if (nums[p1] + nums[p2] == target) return {p1+1, p2+1};

        if (nums[p1] + nums[p2] < target) p1++;
        else p2--;
    }
}

int main() {
    int n, target; cin >> n >> target;
    vi nums(n);

    for (auto &x:nums) cin >> x; 
    vi ans = solve(nums, target);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}