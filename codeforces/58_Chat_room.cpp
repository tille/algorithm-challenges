#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string str, word = "hello";
    int it = 0, cur = 0;
    cin >> str;

    while (it < word.size()) {
        auto t = str.find(word[it], cur);
        if (t != string::npos) cur = t+1, it++;
        else break;
    }

    cout << (it == word.size() ? "YES" : "NO") << endl;
    return 0;
}