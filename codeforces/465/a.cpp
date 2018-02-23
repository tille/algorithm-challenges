#include <iostream>

using namespace std;

int main() {
    int n, ans;
    cin >> n;
    ans = 0;

    for (int i = 1; i <= int(n/2); ++i) {
        if (((n - i) % i) == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}