#include <bits/stdc++.h>
 
using namespace std;
int n;

void solve(int i) {
    int spaces = (n-i)*2;
    while (spaces--) cout << " ";

    string line = "";
    for (int j = 0; j <= i; ++j) {
        line += char(j + '0');
        line += " ";
    }

    for (int j = i - 1; j >= 0; --j) { 
        line += char(j + '0');
        line += " ";
    }

    if (line.back() == ' ') line.pop_back();
    cout << line << endl;
}
 
int main() {
    cin >> n;
    for (int i = 0; i <= n; ++i) solve(i);
    for (int i = n-1; i >= 0; --i) solve(i);
    return 0;
}