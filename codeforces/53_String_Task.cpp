#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define vi vector<int>
 
bool isVowel(char c) {
    vector<char> vowels = {'A', 'O', 'Y', 'E', 'U', 'I'};
    bool valid = false;
    for (char vowel : vowels) 
        valid |= (c == vowel or c == tolower(vowel));
    return valid;
}
int main() {
    string str;
    cin >> str;

    string ans = "";
    for (int i = 0; i < str.size(); ++i) {
        char x = str[i];
        if (!isVowel(x)) {
            x = tolower(x);
            ans += ".";
            ans += x;
        }
    }
    cout << ans << endl;
    return 0;
}