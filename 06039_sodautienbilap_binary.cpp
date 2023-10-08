#include <iostream>
#include <algorithm>

// Hàm thực hiện tìm kiếm nhị phân
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Tính chỉ số trung tâm

        if (arr[mid] == target) {
            return mid; // Trả về chỉ số nếu tìm thấy phần tử
        } else if (arr[mid] < target) {
            left = mid + 1; // Tiếp tục tìm kiếm bên phải của mảng
        } else {
            right = mid - 1; // Tiếp tục tìm kiếm bên trái của mảng
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        int a[n];
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        // Sắp xếp dãy số
        std::sort(a, a + n);

        int foundIndex = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) {
                // Nếu tìm thấy phần tử xuất hiện nhiều hơn 1 lần
                // Áp dụng thuật toán tìm kiếm nhị phân trong mảng đã được sắp xếp
                foundIndex = binarySearch(a, 0, i, a[i]);
                break;
            }
        }

        if (foundIndex != -1) {
            std::cout << a[foundIndex] << std::endl; // In ra phần tử xuất hiện nhiều hơn 1 lần và có số thứ tự nhỏ nhất
        } else {
            std::cout << "NO" << std::endl; // Nếu không tìm thấy, in ra "NO"
        }
    }

    return 0;
}
