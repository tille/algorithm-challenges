#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, ans = "NO";
    cin >> s;

    for (auto x : s) if (x == 'H' or x == 'Q' or x == '9') ans = "YES";
    cout << ans << endl;

    return 0;
}