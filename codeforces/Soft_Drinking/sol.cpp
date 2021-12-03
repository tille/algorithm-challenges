#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<ll, ll>

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int m = (k * l) / nl;
    int s = p / np;
    int sli = c * d;

    cout << floor(min(min(m, s), sli) / n) << endl;
    return 0;
}