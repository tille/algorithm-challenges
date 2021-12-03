#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 50;
int arr[MAXN];
int n;

int getInvCount() {
    set<int> set1;
    set1.insert(arr[0]);
    int invcount = 0;
 
    set<int>::iterator itset1;
 
    for (int i=1; i<n; i++) {
        set1.insert(arr[i]);
        itset1 = set1.upper_bound(arr[i]);
        invcount += distance(itset1, set1.end());
    }
    return invcount;
}
 
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << getInvCount() << endl;
    return 0;
}