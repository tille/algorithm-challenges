#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    string s;
    cin >> s;

    int cont = 0;

    if (s[0] == '4') {
        cout << "NO" << endl;
        return 0;
    }

    for (auto &x : s) {
        if (x != '1' and x != '4') {
            cout << "NO" << endl;
            return 0;
        } 
        
        if (x == '4') cont++;
        else cont = 0;

        if (cont > 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}