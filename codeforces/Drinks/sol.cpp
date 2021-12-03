#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n, sum = 0, num;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        sum += num;
    }

    cout << fixed << setprecision(12);
    cout << (sum / double(n)) << endl;
    return 0;
}