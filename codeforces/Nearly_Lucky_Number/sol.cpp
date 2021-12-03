#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll lucky = 0;
    string n; 
    
    cin >> n;
    for (auto x : n) if (x == '4' or x == '7') lucky++;
    cout << (lucky == 4 or lucky == 7 ? "YES" : "NO") << endl;

    return 0;
}