#include <bits/stdc++.h>

using namespace std;

string solve(string &a, string &b, int mcm) {
    string ans = ""; int i = 0;

    while (mcm--) {
        if (a[i % a.size()] != b[i % b.size()])
            return "-1";
        ans += b[i++ % b.size()];
    }
    return ans;
}

int main () {
    int t;
    cin >> t;

    while (t--) {
        string a; string b;
        cin >> a >> b;

        int mcm = (a.size() / __gcd(a.size() ,b.size())) * b.size();
        cout << solve(a, b, mcm) << endl;
    }
    return 0;
}