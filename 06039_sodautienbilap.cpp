#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); // Tắt đồng bộ hóa giữa iostream và thư viện C
    cin.tie(0); // Gán con trỏ cin tới con trỏ null để tối ưu tốc độ đọc

    int t;
    cin >> t; // Nhập số lượng bộ test

    while (t--) {
        int n;
        cin >> n; // Nhập số lượng phần tử trong dãy số cho mỗi test

        int a[n + 1]; // Khai báo mảng a gồm n + 1 phần tử

        pair<int, int> k; // Khai báo biến k là một cặp số nguyên (int, int)
        k.second = 1e9; // Gán giá trị 1e9 cho k.second (giá trị dự phòng để tìm số thứ tự nhỏ nhất)

        map<int, int> m; // Khai báo một map để lưu trữ số và vị trí của số đó trong dãy số

        // Vòng lặp nhập dãy số và tìm số xuất hiện nhiều hơn 1 lần và có số thứ tự nhỏ nhất
        for (int i = 1; i <= n; i++) {
            cin >> a[i]; // Nhập phần tử thứ i của dãy số

            // Nếu chưa có số a[i] trong map, lưu lại vị trí i của số đó
            if (m[a[i]] == 0)
                m[a[i]] = i;
            else if (k.second > m[a[i]]) {
                // Nếu số a[i] đã xuất hiện trước đó và có vị trí nhỏ hơn k.second,
                // cập nhật lại k.first (giá trị số xuất hiện nhiều hơn 1 lần) và k.second (vị trí nhỏ nhất)
                k.first = a[i];
                k.second = m[a[i]];
            }
        }

        // Nếu tìm thấy số xuất hiện nhiều hơn 1 lần, in ra số đó
        if (k.second != 1e9)
            cout << k.first << endl;
        else
            // Nếu không tìm thấy số nào xuất hiện nhiều hơn 1 lần, in ra "NO"
            cout << "NO" << endl;
    }

    return 0;
}
