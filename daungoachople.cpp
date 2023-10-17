#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra tính hợp lệ của dấu ngoặc đơn trong chuỗi
void solve() {
    string s;
    cin >> s; // Đọc một chuỗi từ đầu vào và lưu vào biến s.

    stack<char> st; // Khai báo một ngăn xếp (stack) chứa các ký tự '('.

    for (char x : s) { // Lặp qua từng ký tự trong chuỗi s.
        if (x == '(') { // Nếu ký tự là dấu ngoặc đơn '('.
            st.push(x); // Đẩy ký tự '(' vào ngăn xếp st.
        } else { // Nếu ký tự là dấu ngoặc đóng ')'.
            if (st.empty()) { // Nếu ngăn xếp rỗng, tức là thiếu dấu ngoặc mở '(' tương ứng.
                cout << "Yes" << endl; // In ra "INVALID" và kết thúc hàm solve với câu lệnh return.
                return;
            } else {
                st.pop(); // Nếu có dấu ngoặc mở '(' tương ứng, loại bỏ nó khỏi ngăn xếp st.
            }
        }
    }

    // Sau khi kiểm tra tất cả các ký tự trong chuỗi s.
    if (st.empty()) {
        cout << "Yes" << endl; // Nếu ngăn xếp st rỗng, tức là mỗi dấu ngoặc mở '(' đã có dấu ngoặc đóng ')' tương ứng và chuỗi hợp lệ.
    } else {
        cout << "No" << endl; // Ngược lại, nếu ngăn xếp không rỗng, tức là thiếu một số dấu ngoặc đóng ')' và chuỗi không hợp lệ.
    }
}

int main() {
    int t;
    cin >> t; // Đọc một số nguyên t từ đầu vào, đại diện cho số lượng test cases.

    while (t--) {
        solve(); // Gọi hàm solve t lần, thực hiện kiểm tra tính hợp lệ của dấu ngoặc trong t test cases.
    }
}
