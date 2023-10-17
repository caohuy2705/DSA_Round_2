#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Đọc một số nguyên n từ đầu vào, đại diện cho số lượng phần tử trong mảng.

    int a[n], b[n]; // Khai báo hai mảng a và b có kích thước n.

    for (int &x : a) 
        cin >> x; // Đọc n phần tử của mảng a từ đầu vào.

    stack<int> st; // Khai báo một ngăn xếp (stack) để lưu trữ chỉ số của các phần tử trong mảng a.

    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push(i); // Nếu ngăn xếp rỗng, đẩy chỉ số i của phần tử vào ngăn xếp st.
        } else {
            while (!st.empty() && a[st.top()] < a[i]) {
                b[st.top()] = a[i]; // Nếu phần tử có chỉ số lớn hơn phần tử ở đỉnh ngăn xếp, gán giá trị của phần tử ở đỉnh ngăn xếp là phần tử a[i].
                st.pop(); // Loại bỏ phần tử ở đỉnh ngăn xếp, vì đã tìm thấy phần tử lớn nhất bên phải của nó.
            }
            st.push(i); // Đẩy chỉ số i của phần tử vào ngăn xếp st để tìm phần tử lớn nhất bên phải của nó.
        }
    }

    // Sau khi duyệt qua tất cả các phần tử trong mảng a, các phần tử còn lại trong ngăn xếp chưa tìm thấy phần tử lớn nhất bên phải của chúng.
    // Do đó, gán giá trị -1 cho các phần tử này trong mảng b.
    while (!st.empty()) {
        b[st.top()] = -1;
        st.pop();
    }

    // In kết quả vào mảng b.
    for (int x : b) {
        cout << x << " ";
    }
}

    /* 
    for(int i = 0; i < n; i++) {
        int res = -1;
        for(int j = i+1; j< n; j++) {
            if(a[j] > a[i]) {
                res = a[j];
                break;
            }
        }
        cout << res << " ";
    }
    */
