#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int mask = 0;
    cin >> s;
    for (auto &x : s) mask |= 1 << (x - 'a');
    if (__builtin_popcount(mask)&1) cout << "IGNORE HIM!" << endl;
    else cout << "CHAT WITH HER!" << endl;
    return 0;
}