#include <bits/stdc++.h>
using namespace std;

vector<string> res; // Vector lưu trữ tất cả các số nhị phân từ 1 đến 10000.

// Hàm khởi tạo các số nhị phân và lưu vào vector res.
void init() {
    queue<string> q; // Hàng đợi sử dụng để sinh các số nhị phân.
    q.push("1"); // Bắt đầu bằng số nhị phân 1.
    res.push_back("1"); // Lưu số nhị phân 1 vào vector res.
    
    // Tiếp tục sinh và lưu các số nhị phân vào vector res cho đến khi đủ 10000 số.
    while (res.size() < 10000) {
        // Lấy ra phần tử đầu hàng đợi (số nhị phân) để tiếp tục sinh các số nhị phân con từ nó.
        string top = q.front();
        q.pop(); // Xóa số nhị phân vừa lấy ra khỏi hàng đợi.
        
        // Sinh các số nhị phân con bằng cách thêm 0 và 1 vào cuối số nhị phân hiện tại.
        res.push_back(top + "0");
        res.push_back(top + "1");
        
        // Đồng thời, đưa các số nhị phân con mới sinh vào hàng đợi để tiếp tục sinh các số con tiếp theo.
        q.push(top + "0");
        q.push(top + "1");
    }
}

int main() {
    init(); // Gọi hàm khởi tạo để tạo và lưu trữ các số nhị phân từ 1 đến 10000 vào vector res.
    
    int t;
    cin >> t; // Đọc số lượng test cases.
    while (t--) {
        int n;
        cin >> n; // Đọc giá trị n cho mỗi test case.
        for (int i = 0; i < n; i++) {
            cout << res[i] << " "; // In ra các số nhị phân từ 1 đến n cho mỗi test case.
        }
        cout << endl; // Xuống dòng sau khi in xong các số nhị phân của một test case.
    }
}
