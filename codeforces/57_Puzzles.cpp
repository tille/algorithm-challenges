#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define vi vector<int>
 
int main() {
    int n, m;
    cin >> n >> m;

    vi puzzles(m);
    for (auto &x : puzzles) cin >> x;
    
    sort(puzzles.begin(), puzzles.end());

    int ans = INT_MAX;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+n-1; j < puzzles.size(); j += n-1) {
            ans = min(puzzles[j] - puzzles[j-n+1], ans);
        }
    }

    cout << ans << endl;
    return 0;
}