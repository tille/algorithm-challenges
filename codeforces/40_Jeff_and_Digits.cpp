#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int n, zero, five, num;
    zero = five = 0;

    cin >> n;
    while (n--) {
        cin >> num;
        if (num == 5) five++;
        if (!num) zero++;
    }

    if (zero) {
        int cant = five / 9;
        if (!cant) cout << 0 << endl;
        else {
            for (int i = 0; i < 9*cant; ++i) cout << 5;
            while (zero--) cout << 0;
            cout << endl;
        }
    } else cout << -1 << endl;

    return 0;
}