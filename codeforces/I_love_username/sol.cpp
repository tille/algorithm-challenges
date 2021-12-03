#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num, small, bigger, ans = 0;

    cin >> n;
    cin >> num;

    small = bigger = num;
    for (int i = 1; i < n; ++i) {
        cin >> num;
        if (num < small) {
            small = num;
            ans++;
        }
        else if (num > bigger) {
            bigger = num;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}