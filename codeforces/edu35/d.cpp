#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1502;

int arr[MAXN];
int n, l, r, q;

int brute_force() {
    int cont = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                cont++;
            }
        }
    }
    int parity = (cont % 2) ? -1 : 1;
    return parity;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int res = brute_force();
    cin >> q;

    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        int trans = (r - l + 1) / 2.0;
        int parity = (trans % 2) ? -1 : 1;
        res *= parity;
        string ans = (res == 1) ? "even" : "odd";
        cout << ans << endl;
    }
    return 0;
}