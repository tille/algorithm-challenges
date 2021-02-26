#include <bits/stdc++.h>

using namespace std;

int main() {

    
 
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (n == 1) {
            cout << k << endl;
        } else if (n == k) {
            cout << 1 << endl;
        } else if (k > n) {
            double yy = (k/(double)n);
            cout << setprecision(15) << ceil(yy) << endl;
        } else if (k < n) {
            if (n % k == 0) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
    return 0;
}