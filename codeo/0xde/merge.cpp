#include <bits/stdc++.h>
 
using namespace std;
 
void merge(int l, int r, int m, vector<int> &arr, vector<int> &temp) {
    int p1 = l, p2 = m + 1;
    for (int i = l; i <= r; ++i) temp[i] = arr[i];
 
    for (int i = l; i <= r; ++i) {
        if (p1 > m) arr[i] = temp[p2++];
        else if (p2 > r) arr[i] = temp[p1++];
        else {
            if (temp[p1] < temp[p2]) arr[i] = temp[p1++];
            else arr[i] = temp[p2++];
        }
    }
}
 
void mergeSort(int l, int r, vector<int> &arr, vector<int> &temp) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m, arr, temp);
        mergeSort(m + 1, r, arr, temp);
        merge(l, r, m, arr, temp);
    }
}
 
int main () {
    int n; cin >> n;
    vector<int> arr(n), helper(n);
 
    for (auto &num : arr) cin >> num;
    mergeSort(0, n-1, arr, helper);
 
    for (auto x : arr) cout << x << " ";
    cout << endl;
 
    return 0;
}