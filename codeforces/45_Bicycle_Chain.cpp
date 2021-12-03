#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n; cin >> n;
    vi a(n);
    for (auto &x : a) cin >> x;

    int m; cin >> m;
    vi b(m);
    for (auto &x : b) cin >> x;

    int cant = 0, maxi = -1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i] % a[j] == 0) {
                int div = b[i] / a[j];
                if (div > maxi) {
                    maxi = div;
                    cant = 1;
                } else if (div == maxi) {
                    cant++;
                }
            }
        }
    }
    cout << cant << endl;

    return 0;
}