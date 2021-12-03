#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, friends, finger, fingers = 0, ans = 0;
    cin >> n; n++;

    for (int i = 0; i < n-1; ++i) {
        cin >> finger;
        fingers += finger;
    }
    fingers--;

    for (auto &x : {1, 2, 3, 4, 5}) if ((fingers + x) % n) ans++;
    cout << ans << endl;
    return 0;
}