#include <iostream>
#include <algorithm>
using namespace std;

int n;
int main () {
    int t;
    cin >> t; // Nhập số lượng trường hợp cần xử lý

    while (t--) { // Xử lý từng trường hợp
        cin >> n; // Nhập số lượng phần tử trong dãy số
        int a[n]; // Khai báo mảng chứa dãy số

        // Nhập các phần tử của dãy số
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n); // Sắp xếp dãy số theo thứ tự tăng dần

        long long so1 = 0, so2 = 0; // Khởi tạo hai số lớn ban đầu

        // Xây dựng hai số lớn từ dãy số đã sắp xếp
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                so1 = so1 * 10 + a[i]; // Xây dựng số lớn bằng cách ghép các phần tử ở vị trí chẵn
            else
                so2 = so2 * 10 + a[i]; // Xây dựng số lớn bằng cách ghép các phần tử ở vị trí lẻ
        }

        cout << so1 + so2 << endl; // In ra tổng của hai số lớn
    }
}
