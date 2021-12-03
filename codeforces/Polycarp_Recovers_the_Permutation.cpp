#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n, t; cin >> t;
    while (t--) {
        cin >> n;
        vi arr(n);

        for (auto &x : arr) cin >> x;
        reverse(arr.begin(), arr.end());

        for (auto &x : arr) cout << x << " ";
        cout << endl;
    }   
    return 0;
}