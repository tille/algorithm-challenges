#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int n;
    ll mini = LLONG_MAX, cant = 0, ans = 0, num;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num < mini) {
            mini = num;
            cant = 1;
            ans = i;
        } else if (num == mini) cant++;
    }

    if (cant > 1) cout << "Still Rozdil" << endl;
    else cout << ans+1 << endl;

    return 0;
}