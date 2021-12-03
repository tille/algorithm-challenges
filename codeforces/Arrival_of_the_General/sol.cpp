#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n, left = 0, right, ans;
    cin >> n;

    right = 0;
    vi nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] <= nums[right]) right = i;
        if (nums[i] > nums[left]) left = i;
    }
    ans = left + n - 1 - right;
    if (right < left) ans--;

    cout << ans << endl;
    return 0;
}