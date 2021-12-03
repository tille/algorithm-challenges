#include <iostream>

using namespace std;
const int MAXN = 100005;

int arr[MAXN];

int main() {
    int n, a, b, timezone;
    long long tot = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> a >> b;
    a--; b--;
    int range = b - a;
    long long sum = 0;

    for (int i = 0; i < range; ++i) {
        sum += arr[i];
    }
    tot = sum;
    timezone = a;

    for (int i = 1; i < n; ++i) {
        sum = sum - arr[i - 1] + arr[((i + (range - 1)) % n)];

        if (sum > tot) {
            tot = sum;
            timezone = ((a - i + n) % n);
        } else if (sum == tot) {
            int ans = ((a - i + n) % n);
            if (ans < timezone) {
                timezone = ans;
            }
        }
    }

    cout << timezone + 1 << endl;

    return 0;
}