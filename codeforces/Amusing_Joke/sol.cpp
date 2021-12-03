#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    if (a.size() + b.size() != c.size()) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> ini(27, 0), fin(27, 0);

    for (auto &x:a) ini[x-'A']++;
    for (auto &x:b) ini[x-'A']++;
    for (auto &x:c) fin[x-'A']++;

    for (int i = 0; i < ini.size(); ++i) {
        if (ini[i] != fin[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}