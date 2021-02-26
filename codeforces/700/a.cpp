#include <bits/stdc++.h>

using namespace std;

int main() { 
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int p = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (p) {
                if (s[i] != 'a') s[i] = 'a';
                else s[i] = 'b';
            } else {
                if (s[i] != 'z') s[i] = 'z';
                else s[i] = 'y';
            } 
            p = (p + 1) % 2;
        }
        cout << s << endl;
    }
    return 0;
}