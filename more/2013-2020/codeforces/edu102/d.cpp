#include <bits/stdc++.h>

using namespace std;

#define maxn 300000
#define max_logn 20

struct node {
    int mn, mx;

    node(int i, int j) : mn(i), mx(j) {};
    node(){}
};

node st[maxn][max_logn];

void build (int n, vector<int> &a) {
    for (int i = 0; i < n; ++i)
        st[i][0] = node(i, i);
    
    for (int j = 1; (1<<j) <= n; ++j) {
        for (int i = 0; (i + (1<<j) - 1) < n; ++i) {
            int mn, mx;
            node f = st[i][j - 1];
            node l = st[i + (1 << (j - 1) )][j - 1];

            mn = (a[f.mn] < a[l.mn]) ? f.mn : l.mn;
            mx = (a[f.mx] > a[l.mx]) ? f.mx : l.mx;

            st[i][j] = node(mn, mx);
        }
    }
}

int query_min (int i, int j, vector<int> &a) {
    int k = log2(j - i + 1);
    if (a[st[i][k].mn] < a[st[j - (1 << k) + 1][k].mn]) return st[i][k].mn;
    else return st[j -  (1 << k) + 1][k].mn;
}


int query_max (int i, int j, vector<int> &a) {
    int k = log2(j - i + 1);
    if (a[st[i][k].mx] > a[st[j - (1 << k) + 1][k].mx]) return st[i][k].mx;
    else return st[j - (1 << k) + 1][k].mx;
}

int main () {
    int t; cin >> t;

    while (t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;

        vector<int> a;
        int idx = 0;
        a.push_back(idx);

        for (int i = 0; i < s.size(); ++i) {
            int mv = s[i] == '-' ? -1 : 1;
            idx += mv;
            a.push_back(idx);
        }

        build(a.size(), a);
        // for (int i = 0; i < a.size(); ++i)
        //     cout << a[i] << " ";
        // cout << endl;

        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;

            int mn_prefix = a[query_min(0, l - 1, a)];
            int mx_prefix = a[query_max(0, l - 1, a)];

            int mn_suffix, mx_suffix;
            if (r + 1 == a.size()) {
                cout << abs(mx_prefix - mn_prefix) + 1 << endl;
                continue;
            } else {
                mn_suffix = a[query_min(r + 1, a.size() - 1, a)] - a[r] + a[l - 1];
                mx_suffix = a[query_max(r + 1, a.size() - 1, a)] - a[r] + a[l - 1];
            }

            int mini = min(mn_prefix, mn_suffix);
            int maxi = max(mx_prefix, mx_suffix);
            cout << abs(maxi - mini) + 1 << endl;
        }

        // for (int i = 0; i < a.size(); ++i)
        //     cout << a[i] << " ";
        // cout << endl;

        // int t = query_min(1,8,a);
        // cout << a[t] << endl;

        // for (int i = 0; i < 7; ++i) {
        //     for (int j = 0; (1<<j) <= 7; ++j) {
        //         cout << st[i][j].mn << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    return 0;
}