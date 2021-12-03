#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define vi vector<int>

bool validate(string str) {
    char prev = str[0];
    bool valid = true;
    for (auto &x : str) valid &= (x == prev);
    return valid;
}
 
int main() {
    string s;
    cin >> s;

    if (s.size() < 8) {
        cout << "NO" << endl;
    } else {
        bool valid = false;
        for (int i = 0; i < s.size()-6; ++i) {
            if (validate(s.substr(i, 7)) && s[i+7] != s[i+6]) {
                valid = true;
            }
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}