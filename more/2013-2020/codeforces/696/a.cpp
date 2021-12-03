#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;

    while (t--) {
        int n; string b;
        cin >> n >> b;

        string a; int last;
        for (int i = 0; i < b.size(); ++i) {
            if (!i) {
                a += '1';
                last = ((b[0] - '0') + 1);
                continue;
            }

            int t = ((b[i] - '0') + 1);

            if (t == last) {
                a += '0';
                last = (b[i] - '0');
            } else {
                a += '1';
                last = t;
            }
        }
        cout << a << endl;
    }
    return 0;
}