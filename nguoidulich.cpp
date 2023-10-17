#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1e9;

int n;
int C[15][15];
int path[15];
bool visited[15];
int minCost = INF;
int f_star = INF; // Lưu trữ giá trị kỷ lục tốt nhất

// Hàm tính giá trị hàm g
int calculate_g(int k) {
    int g_val = 0;
    for (int i = 0; i < k - 1; ++i) {
        g_val += C[path[i]][path[i + 1]];
    }
    return g_val;
}

void Branch_And_Bound(int k) {
    for (int ak = 1; ak < n; ++ak) {
        if (!visited[ak] && C[path[k - 1]][ak] != 0) {
            visited[ak] = true;
            path[k] = ak;
            int g_val = calculate_g(k + 1);

            if (k == n - 1) {
                // Đã đi qua tất cả các thành phố, kiểm tra xem có đường đi trở lại thành phố 1 hay không
                if (C[ak][0] != 0) {
                    int totalCost = g_val + C[ak][0];
                    if (totalCost < f_star) {
                        f_star = totalCost;
                        // Cập nhật đường đi tối ưu
                        for (int i = 0; i < n; ++i) {
                            path[i]++;
                        }
                    }
                }
            } else if (g_val + C[ak][0] <= f_star) {
                // Nếu giá trị hàm g kết hợp với chi phí trở về thành phố 1 nhỏ hơn f_star
                Branch_And_Bound(k + 1);
            }

            visited[ak] = false; // Quay lui
        }
    }
}

int main() {
    cin >> n;
    // ... (đoạn nhập dữ liệu và khởi tạo ban đầu tương tự như trước)

    visited[0] = true; // Thành phố 1 đã được đi qua
    path[0] = 0; // Thêm thành phố 1 vào đường đi

    Branch_And_Bound(1);

    cout << f_star << endl; // In ra kết quả tối ưu

    return 0;
}
