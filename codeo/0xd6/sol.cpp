#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    cout << min(abs(x - y), n - abs(x - y)) << endl;
    return 0;
}