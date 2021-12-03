#include <iostream>
using namespace std;

const int MAXN = 10;
int arr[MAXN];
int temp[MAXN];

int merge(int left, int mid, int right) {
    int i = left;
    int j = mid+1;
    int k = left;
    int invcnt = 0;

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

int mergeSort(int left, int right) {
    int invcnt = 0;
    if (right > left) {
        int mid = (left + right) / 2;

        invcnt += mergeSort(left, mid);
        invcnt += mergeSort(mid+1, right);
        invcnt += merge(left, mid, right);
    }
    return invcnt;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << mergeSort(0, n-1) << endl;
    return 0;
}