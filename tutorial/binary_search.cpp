int max_search(int l, int r, int k) {
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (a[mid] <= k) l = mid;
    else r = mid - 1;
  }
  return l; 
}

int min_search(int l, int r, int k) {
  while (l < r) {
    int mid = (l + r) / 2;
    if (a[mid] >= k) r = mid;
    else l = mid + 1;
  }
  return l;
}

usage:
a[] = {2,3,4,4,4,5}
max_search(0, 5, 4) -> returns 4
min_search(0, 5, 4) -> returns 2
