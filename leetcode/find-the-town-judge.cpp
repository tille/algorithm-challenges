#include <bits/stdc++.h>

using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> g[N + 1];

    for (int i = 0; i < trust.size(); ++i) {
        int a = trust[i][0];
        int b = trust[i][1];
        g[a].push_back(b);
    }

    vector<int> possible;
    for (int i = 1; i <= N; ++i)
        if (!g[i].size())
            possible.push_back(i);
    
    for (int i = 0; i < possible.size(); ++i) {
        int num = possible[i];
        int ans = 0;
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < g[j].size(); ++k) {
                if (g[j][k] == num) ans++;
            }
        }
        if (ans == N - 1) return num;
    }
    return -1;
}

int main() {
    int n = 2;
    vector<vector<int>> a(1);
    a[0].push_back(1);
    a[0].push_back(2);
    
    int ans = findJudge(n, a);
    cout << ans << endl;

    return 0;
}