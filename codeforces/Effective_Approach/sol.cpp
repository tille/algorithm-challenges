#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<ll, ll>

int main() {
    int n, num, m;
    pi ans = {0, 0}, pos;
    
    cin >> n;
    vector<pi> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> num;
        nums[i] = {num, i};
    }
    sort(nums.begin(), nums.end());

    cin >> m;
    while (m--) {
        cin >> num;
        pos = *lower_bound(nums.begin(), nums.end(), pi({num, 0}));
        ans.first += pos.second + 1;
        ans.second += n - pos.second;
    }

    cout << ans.first << " " << ans.second << endl;
    return 0;
}