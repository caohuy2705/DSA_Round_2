#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {  // Nếu chỉ còn một phần tử trong đoạn
            if (arr[low] == x)  // Nếu phần tử duy nhất là số cần tìm
                return 1;  // Trả về 1 (số cần tìm có mặt trong mảng)
            return -1;  // Trả về -1 (số cần tìm không có mặt trong mảng)
        }

        // Tính toán vị trí ước lượng của x dựa trên interpolation formula
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x)  // Nếu phần tử tại vị trí ước lượng là số cần tìm
            return 1;  // Trả về 1 (số cần tìm có mặt trong mảng)

        if (arr[pos] < x)
            low = pos + 1;  // X nằm ở phía bên phải vị trí ước lượng
        else
            high = pos - 1;  // X nằm ở phía bên trái vị trí ước lượng
    }

    return -1;  // Trả về -1 (số cần tìm không có mặt trong mảng)
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, x;
        cin >> n >> x;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int result = interpolationSearch(arr, n, x);
        cout << result << endl;
    }

    return 0;
}
