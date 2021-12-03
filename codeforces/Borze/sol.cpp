#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    string s; cin >> s;
    string ans = "";
    int cur = 0;
    while (true) {
        if (s[cur] == '-') {
            ans += s[cur+1] == '.' ? "1" : "2"; 
            cur += 2;
        } else {
            ans += "0";
            cur++;
        }
        if (cur >= s.size()) break;
    }
    cout << ans << endl;
    return 0;
}