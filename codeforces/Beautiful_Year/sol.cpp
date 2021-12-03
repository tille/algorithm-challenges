#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

vector<int> ans;

void backtracking(string num, set<int> &seen) {
    if (num.size() == 4) {
        ans.push_back(stoi(num));
        return ;
    }
    for (int i = 0; i < 10; ++i) {
        if (!seen.count(i)) {
            seen.insert(i);
            num += char(i + '0');
            backtracking(num, seen);
            num = num.substr(0, num.size()-1);
            seen.erase(i);
        }
    }
}

int main() {
    set<int> seen;
    backtracking("", seen); 

    int n; cin >> n;
    cout << *upper_bound(ans.begin(), ans.end(), n) << endl;
    return 0;
}