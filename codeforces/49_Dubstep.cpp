#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define vi vector<int>
 
int main() {
    string s;
    cin >> s;

    string ans = "";
    int space = 0;
    for (int i = 0; i < s.size(); ) {
        if (i >= s.size() - 2) {
            ans += s.substr(i, s.size() - i);
            break;
        }

        string cur = s.substr(i, 3);
        if (cur == "WUB") {
            if (space) {
                ans += " ";
                space = 0;
            }
            i += 3;
        } else {
            space = 1;
            ans += s[i];
            i++;
        }
    }

    if (ans[ans.size()-1] == ' ') ans.pop_back();
    cout << ans << endl;
    return 0;
}