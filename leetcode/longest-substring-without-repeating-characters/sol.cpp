#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> freq;

int solve(string s) {
    char cur, prev;
    int l, r, ans;
    l = r = ans = 0;

    while (r < s.size()) {
        cur = s[r];
        freq[cur]++;
        r++;

        while (freq[cur] > 1) {
            prev = s[l];
            freq[prev]--;
            l++;
        }
        ans = max(ans, r - l);
    }
    return ans;
}

int solve2(string s) {
    int l, r, ans;
    l = r = ans = 0;
    char cur;

    while (r < s.size()) {
        cur = s[r++];

        if (freq.count(cur)) l = max(l, freq[cur]);
        freq[cur] = r;
        ans = max(ans, r - l);
    }
    return ans;
}

int main() {
    string s = "abcabcbb";
    cout << solve2(s) << endl;
    return 0;
}