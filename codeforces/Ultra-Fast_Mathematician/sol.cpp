#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    string a, b, ans;
    cin >> a >> b; ans = a;

    for (int i = 0; i < a.size(); ++i)
        ans[i] = ((a[i] - '0') ^ (b[i] - '0')) + '0';

    cout << ans << endl;
    return 0;
}