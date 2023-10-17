#include <iostream>
#include <algorithm>
using namespace std;

int merge(int arr[], int left, int mid, int right, int k) {
    int count = 0;
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && arr[j] - arr[i] < k) {
            count += (mid - i + 1);
            j++;
        }
    }
    return count;
}

int mergeSortAndCount(int arr[], int left, int right, int k) {
    int count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count += mergeSortAndCount(arr, left, mid, k);
        count += mergeSortAndCount(arr, mid + 1, right, k);
        count += merge(arr, left, mid, right, k);

        inplace_merge(arr + left, arr + mid + 1, arr + right + 1);
    }
    return count;
}

int countPairsWithDifferenceLessThanK(int arr[], int n, int k) {
    sort(arr, arr + n);
    return mergeSortAndCount(arr, 0, n - 1, k);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int result = countPairsWithDifferenceLessThanK(arr, n, k);
        cout << result << endl;
    }

    return 0;
}
