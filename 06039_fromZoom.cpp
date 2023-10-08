#include <iostream>
#include <vector>
using namespace std;

// Hàm tìm kiếm tuyến tính trong mảng đã sắp xếp
int interpolationSearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            // Nếu chỉ có một phần tử và không phải là target, trả về -1
            if (arr[left] == target)
                return left;
            return -1;
        }

        // Sử dụng interpolation formula để tính toán vị trí tiềm năng của target
        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == target)
            return pos;

        // Tiếp tục tìm kiếm trái hoặc phải tùy vào giá trị tại vị trí pos
        if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }

    // Không tìm thấy target trong mảng
    return -1;
}

// Hàm tìm số có tần số xuất hiện nhiều nhất trong mảng
int findFrequency(const vector<int>& arr) {
    int n = arr.size();
    int candidate = arr[0];
    int count = 1;

    // Tìm candidate là ứng cử viên cho số có tần số xuất hiện nhiều nhất
    for (int i = 1; i < n; ++i) {
        if (arr[i] == candidate)
            count++;
        else {
            count--;
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            }
        }
    }

    count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == candidate)
            count++;
    }

    // Nếu số candidate có tần số xuất hiện lớn hơn N / 2, trả về candidate
    if (count > n / 2)
        return candidate;

    // Ngược lại, không tìm thấy số thỏa mãn yêu cầu
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; ++i)
            cin >> arr[i];

        // Tìm số có tần số xuất hiện nhiều nhất trong mảng
        int candidate = findFrequency(arr);

        if (candidate != -1) {
            // Tính tần số xuất hiện của số candidate trong mảng
            int frequency = 0;
            for (int num : arr) {
                if (num == candidate)
                    frequency++;
            }

            // Nếu tần số xuất hiện lớn hơn N / 2, in ra kết quả
            if (frequency > N / 2)
                cout << candidate << endl;
            else
                cout << "NO" << endl;
        } else {
            // Không tìm thấy số thỏa mãn yêu cầu
            cout << "NO" << endl;
        }
    }

    return 0;
}
