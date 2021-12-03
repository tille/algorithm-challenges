#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    string s, num = "";
    vi nums;
    cin >> s;

    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size() || s[i] == '+') {
            nums.push_back(stoi(num));
            num = "";
        } else num += s[i];
    }

    sort(nums.begin(), nums.end());

    string ans = "";
    for (auto &x : nums) 
        ans += to_string(x) + '+';
    cout << ans.substr(0, ans.size()-1) << endl;
    return 0;
}