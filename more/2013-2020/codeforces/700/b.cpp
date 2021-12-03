#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {

    cout << std::setprecision(20);
    int t;
    cin >> t;

    while (t--) {
        ll A, B, n;
        cin >> A >> B >> n;

        vector<ll> a(n), b(n);
        for (ll &x: a) cin >> x;
        for (ll &x: b) cin >> x;

        ll health = 0;
        for (int i = 0; i < n; ++i)
            health += ceil(b[i] / (double)A) * a[i];
        
        int exit = false;
        health = B - health;
        for (int i = 0; i < n && !exit; ++i) {
            if (health + a[i] > 0) {
                cout << "yes" << endl;
                exit = true;
            };
        }
        if (!exit)
            cout << "no" << endl;
    }
    return 0;
}