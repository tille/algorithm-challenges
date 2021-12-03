#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, int> letters;
    string str = "";
    for (auto &x : s) letters[x]++;

    for (auto [k, v] : letters) {
        if (v % n != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (auto [k, v] : letters) {
        int temp = v/n;
        while (temp--) {
            str += k;
        }
    }

    string ans = "";
    while (n--) ans += str;
    cout << ans << endl;
    
    return 0;
}