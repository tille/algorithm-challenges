#include <iostream>
using namespace std;

#define ll long long

const int MAXN = 200005;
int arr[MAXN];
int temp[MAXN];

ll merge(int left, int mid, int right) {
    int i = left;
    int j = mid+1;
    int k = left;
    ll invcnt = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invcnt += (mid - i) + 1;
        }
    }

    while (i <= mid) 
        temp[k++] = arr[i++];

    while (j <= right) 
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return invcnt;
}

ll mergeSort(int left, int right) {
    ll invcnt = 0;
    if (right > left) {
        int mid = (left + right) / 2;

        invcnt += mergeSort(left, mid);
        invcnt += mergeSort(mid+1, right);
        invcnt += merge(left, mid, right);
    }
    return invcnt;
}

int main() {
    int n, t;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << mergeSort(0, n-1) << endl;
    }
    return 0;
}