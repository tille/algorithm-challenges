#include <bits/stdc++.h>

using namespace std;

#define maxn 1000
#define log_two_n 10

int SpT[maxn][log_two_n];

void build (int n, int a[]) {
    for (int i = 0; i < n; ++i)
        SpT[i][0] = i;

    for (int j = 1; (1<<j) <= n; ++j)
        for (int i = 0; i + (1<<j) - 1 < n; ++i)
            if (a[SpT[i][j-1]] < a[SpT[i + (1<<(j-1))][j-1]])
                SpT[i][j] = SpT[i][j-1];
            else
                SpT[i][j] = SpT[i + (1<<(j-1))][j-1];
}

int query (int a[], int i, int j) {
    int k = (int)(log((double)j-i+1) / log(2.0));
    if (a[SpT[i][k]] < a[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
    else return SpT[j-(1<<k)+1][k];
}

int main () {
    int a[7] = {18, 17, 13, 19, 15, 11, 20};
    build(7, a);

    int i = 0, j = 6;
    int ans = query(a, i, j);
    cout << ans << endl;

    return 0;
}