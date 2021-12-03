#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n, ans = 0; 
    char c, prev;
    string s;
    
    cin >> n;
    cin >> prev;

    for (int i = 0; i < n - 1; ++i) {
        cin >> c;
        if (c == prev) ans++;
        prev = c;
    }

    cout << ans << endl;
    return 0;
}