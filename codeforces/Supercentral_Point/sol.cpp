#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pi pair<int, int>

int verify(pi a, pi b) {
    if (a.first == b.first && a.second < b.second) return 0;
    if (a.first == b.first && a.second > b.second) return 1;
    if (a.second == b.second && a.first < b.first) return 2;
    if (a.second == b.second && a.first > b.first) return 3;
    return -1;
}

int main() {
    int n; 
    cin >> n;

    vector<pi> points(n);
    for (auto &[a, b] : points) cin >> a >> b;

    int ans = 0;
    for (auto &p1 : points) {
        int coordinates = 0;
        for (auto &p2 : points) {
            int pos = verify(p1, p2);
            if (pos != -1) coordinates |= 1 << pos;
        }
        if (15 == coordinates) ans++; 
    }
    cout << ans << endl;

    return 0;
}