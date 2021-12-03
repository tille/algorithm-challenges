#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int c = __gcd(2020, 2021);
        cout << c << endl;
        // if (n % 2020 == 0 or n % 2021 == 0) {
        //     cout << "yes1" << endl;
        //     continue;
        // } 
        // if (n < 2021) {
        //     cout << "no" << endl;
        //     continue;
        // }
        // if (n % 2020) {
        //     int a = n / 2020;
        //     int b = (n - (2020 * a));
        //     if (b % 2021 == 0) {
        //         cout << "yes2" << endl;
        //         continue;
        //     }
        // }
        // if (n % 2021) {
        //     int a = n / 2021;
        //     int b = (n - (2021 * a));
        //     if (b % 2020 == 0) {
        //         cout << "yes3" << endl;
        //         continue;
        //     }
        // }
        // cout << "no" << endl;

    }
    return 0;
}