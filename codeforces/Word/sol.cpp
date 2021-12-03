#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, lower = "", upper = "";
    int lowercase = 0, uppercase = 0;

    cin >> s;
    for (auto x : s) {
        if (islower(x)) lowercase++;
        else uppercase++;

        lower += tolower(x);
        upper += toupper(x);
    }

    cout << (lowercase >= uppercase ? lower : upper) << endl;
    return 0;
}