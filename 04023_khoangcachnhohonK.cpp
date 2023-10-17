#include <iostream>
#include <algorithm>
using namespace std;

// Hàm merge: đếm số cặp phần tử có hiệu nhỏ hơn K trong hai mảng con đã được sắp xếp
int merge(int arr[], int left, int mid, int right, int k) {
    int count = 0;
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && arr[j] - arr[i] < k) {
            count += (mid - i + 1); // Tăng số lượng cặp khi tìm thấy arr[j] - arr[i] < k
            j++;
        }
    }
    return count;
}

// Hàm mergeSortAndCount: Áp dụng thuật toán chia và trị bằng kỹ thuật merge sort để đếm số cặp thỏa mãn yêu cầu
int mergeSortAndCount(int arr[], int left, int right, int k) {
    int count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count += mergeSortAndCount(arr, left, mid, k); // Đệ quy tính số cặp trong mảng con bên trái
        count += mergeSortAndCount(arr, mid + 1, right, k); // Đệ quy tính số cặp trong mảng con bên phải
        count += merge(arr, left, mid, right, k); // Gọi hàm merge để đếm số cặp trong cả hai mảng con đã được sắp xếp

        inplace_merge(arr + left, arr + mid + 1, arr + right + 1); // Trộn hai mảng con đã được sắp xếp lại
    }
    return count;
}

// Hàm countPairsWithDifferenceLessThanK: Hàm gọi chính của bài toán
int countPairsWithDifferenceLessThanK(int arr[], int n, int k) {
    sort(arr, arr + n); // Sắp xếp mảng đầu vào
    return mergeSortAndCount(arr, 0, n - 1, k); // Gọi hàm mergeSortAndCount để đếm số cặp phần tử thỏa mãn yêu cầu
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

        int result = countPairsWithDifferenceLessThanK(arr, n, k); // Gọi hàm để tính kết quả và lưu vào biến result
        cout << result << endl; // In kết quả
    }

    return 0;
}
