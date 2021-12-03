#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main() {
    vi v(3); int ans, temp;
    for (auto &x : v) cin >> x;

    ans = sqrt(v[1] * v[2] /v[0]);
    temp = sqrt(v[2] * v[0] / v[1]);
    ans += v[0] / temp;
    ans += temp;

    cout << ans*4 << endl;
    return 0;
}