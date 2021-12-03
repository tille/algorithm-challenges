#include <iostream>

using namespace std;

int kingdom;
int n, x, y, ans;

int identifyKingdom() {
    if (x > y) return -1;
    else if (x < y) return 1;
    else return 0;
}

int main() {
    string s;
    cin >> n;

    x = y = ans = 0;

    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'U') y++;
        else x++;

        if (i == 0) {
            kingdom = identifyKingdom();
        } else {
            int k = identifyKingdom();
            if (k != 0 && k != kingdom) {
                ans++;
                kingdom = k;
            }
        }
    }
    cout << ans << endl;
    return 0;
}