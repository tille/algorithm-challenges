#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
 
char bigOne(string s1, string s2, bool swapped) {
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i]) continue;
        else if (s1[i] < s2[i]) return (swapped ? '>' : '<');
        else return (swapped ? '<' : '>');
    }
    return '=';
}

int main() {
    int t; cin >> t;

    while (t--) {
        string x1, x2;
        int p1, p2;
        cin >> x1 >> p1 >> x2 >> p2;

        if (x1.size() + p1 > x2.size() + p2) {
            cout << '>' << endl;
            continue;
        }

        if (x2.size() + p2 > x1.size() + p1) {
            cout << '<' << endl;
            continue;
        }

        bool swapped = false;
        if (x1.size() > x2.size()) {
            swap(x1, x2);
            swapped = true;
        }
        while (x1.size() < x2.size()) x1 += '0';

        char ans = bigOne(x1, x2, swapped);
        cout << ans << endl;
    }
    return 0;
}