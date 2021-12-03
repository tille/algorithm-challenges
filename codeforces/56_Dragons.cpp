#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define vi vector<int>
 
int main() {
    ll s, n; cin >> s >> n;

    vector<pair<int, int>> dragons(n);
    for (auto &dragon : dragons)
        cin >> dragon.first >> dragon.second;

    sort(dragons.begin(), dragons.end());

    int it = 0;
    while (s > dragons[it].first) {
        s += dragons[it].second;
        it++;
        if (it == n) break;
    }

    cout << (it == n ? "YES" : "NO") << endl;
    return 0;
}