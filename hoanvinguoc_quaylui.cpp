#include <bits/stdc++.h>
using namespace std;

int n, a[100], rev_used[100];

void inkq() {
    for(int i = n; i >= 1; i--) { // CHANGED: Duyệt từ n xuống 1 để in ra hoán vị ngược
        cout << a[i];
    }
    cout << endl;
}

void Try(int i) { 
    //duyet cac kha nang ma a[i] co the nhan duoc
    for(int j = 1; j <= n; j++) { 
        // xet xem co the gan a[i] = j hay khong 
        if(rev_used[j] == 0) { 
            a[i] = j; 
            rev_used[j] = 1; // CHANGED: Dùng mảng rev_used để đánh dấu các số đã được sử dụng
            if(i == n) { //1. Giải P với điều kiện dừng i ==n : In ra hoán vị
                inkq(); 
            }
            else { // 2. Giải P' giống như P: Recursion(P')
                Try(i+1); //gọi đệ quy 
            }
            //backtrack
            rev_used[j] = 0; // CHANGED: Đánh dấu số j chưa được sử dụng sau khi thực hiện hàm Try(i+1)
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        Try(1);
    }
    return 0;
}
