#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n; cin >> n;
    map<string, int> m;
    m["++X"] = m["X++"] = 1; 
    m["X--"] = m["--X"] = -1;

    string s;
    int ans = 0;

    while (n--) {
        cin >> s;
        ans += m[s];
    }
    cout << ans << endl;
    return 0;
}