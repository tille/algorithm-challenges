#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int existsPair = 0;
        for (auto &x : s) if ((x - '0') % 2 == 0) existsPair = 1;

        if ((s.back() - '0') % 2 == 0) {
            cout << 0 << endl;
        } else if ((s.front() - '0') % 2 == 0) {
            cout << 1 << endl;
        } else if (existsPair) {
            cout << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}