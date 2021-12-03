#include <bits/stdc++.h>

using namespace std;

bool solve(string s) {
    int mask = 0;
    for (auto x : s) {
        int pos = x - 'a';
        if (mask & 1 << pos) return false;
        mask |= 1 << (pos);
    }
    return true;
}

int main () {
    string s; cin >> s;
    cout << (solve(s) ? "no" : "yes") << endl;

    return 0;
}