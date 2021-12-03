#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int e;
        cin >> e;

        set<int> s;
        while (e--) {
            int a, b;
            cin >> a >> b;
            s.insert(a);
            s.insert(b);
        }

        cout << s.size() << endl;
    }
    return 0;
}