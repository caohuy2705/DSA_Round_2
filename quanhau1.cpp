#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, ans, c1[50], c2[50], c3[50];

// Hàm đệ quy để thử đặt quân hậu lên hàng thứ x của bàn cờ
void Try(int x)
{
    // Nếu đã đặt N quân hậu thành công lên bàn cờ (x đã vượt quá n+1)
    if (x == n + 1)
    {
        ans++; // Tăng số lượng cách đặt quân hậu lên bàn cờ
        return; // Kết thúc đệ quy
    }
    
    // Thử tất cả các cột có thể đặt quân hậu lên hàng x
    for (int i = 1; i <= n; i++)
    {
        // Kiểm tra xem có thể đặt quân hậu vào ô (x, i) trên bàn cờ không
        if (c1[i] == 0 && c2[i + x] == 0 && c3[x - i + n] == 0)
        {
            c1[i] = c2[i + x] = c3[x - i + n] = 1; // Đánh dấu vị trí đã có quân hậu đặt vào
            Try(x + 1); // Gọi đệ quy để thử đặt quân hậu lên hàng tiếp theo (x + 1)
            c1[i] = c2[i + x] = c3[x - i + n] = 0; // Gỡ bỏ quân hậu từ vị trí (x, i) để thử các vị trí khác
        }
    }
}

int main()
{
    int t;
    cin >> t; // Đọc vào số lượng bài toán cần giải
    
    while (t--)
    {
        ans = 0; // Đặt biến ans về 0 để chuẩn bị giải bài toán mới
        
        // Đánh dấu lại bàn cờ là trống
        for (int i = 0; i < 20; i++)
            c1[i] = c2[i] = c3[i] = 0;
        
        cin >> n; // Đọc vào kích thước bàn cờ của bài toán hiện tại
        
        Try(1); // Gọi hàm đệ quy để giải bài toán và lưu kết quả vào biến ans
        cout << ans << endl; // In ra kết quả của bài toán hiện tại
    }
}
