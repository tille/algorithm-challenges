#include <bits/stdc++.h>

using namespace std;
map<string, int> goals;

int main() {
    int n;
    cin >> n;
    string s;

    while (n--) {
        cin >> s;
        goals[s]++;
    }

    int ans = 0;
    string last;
    for (auto [k, v] : goals) {
        if (v > ans) {
            ans = v;
            last = k;
        }
    }
    cout << last << endl;
    return 0;
}