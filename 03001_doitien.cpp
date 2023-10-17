#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T; // Biến lưu số lượng bộ test
    cin >> T; // Đọc số lượng bộ test từ input

    int denominations[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    // Mảng denominations chứa các mệnh giá tiền theo thứ tự giảm dần.

    while (T--) { // Bắt đầu vòng lặp qua từng bộ test
        int N; // Biến lưu giá trị tiền cần đổi của bộ test hiện tại
        cin >> N; // Đọc giá trị tiền cần đổi từ input

        int numNotes = 0; // Biến lưu số tờ tiền đã đổi, ban đầu đặt bằng 0.

        // Duyệt qua từng mệnh giá tiền trong mảng denominations
        for (int i = 0; i < sizeof(denominations) / sizeof(denominations[0]); i++) {
            // Trong mỗi lượt lặp, kiểm tra xem giá trị tiền cần đổi (N) có lớn hơn hoặc bằng mệnh giá tiền hiện tại (denominations[i]) không
            while (N >= denominations[i]) {
                // Nếu có, tiến hành đổi tiền:
                // - Giảm giá trị tiền cần đổi (N) đi mức mệnh giá tiền hiện tại (denominations[i])
                // - Tăng số tờ tiền (numNotes) lên 1
                N -= denominations[i];
                numNotes++;
            }
        }

        // In ra kết quả số tờ tiền cần thiết sau khi đổi tiền cho bộ test hiện tại
        cout << numNotes << endl;
    }

    return 0;
}
