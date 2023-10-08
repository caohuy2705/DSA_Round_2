#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Hàm tìm tần suất của một phần tử trong mảng
int findFrequency(vector<int>& arr, int num) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == num) {
            count++;
        }
    }
    return count;
}

// Hàm tìm phần tử đầu tiên bị lặp trong mảng
int findMajorityElement(vector<int>& arr) {
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    // Áp dụng thuật toán Interpolation Search
    while (start <= end) {
        int mid = start + ((end - start) / (arr[end] - arr[start])) * (arr[end] - arr[start]);
        int frequency = findFrequency(arr, arr[mid]);

        // Nếu tần suất lớn hơn n/2, tức là phần tử đạt yêu cầu đa số, trả về giá trị đó
        if (frequency > n / 2) {
            return arr[mid];
        }
        // Nếu tần suất bằng n/2, không có phần tử nào đạt yêu cầu đa số
        else if (frequency == n / 2) {
            return -1;
        }
        // Nếu phần tử tại vị trí mid nhỏ hơn phần tử cuối cùng, tìm kiếm phía bên phải của mảng
        else if (arr[mid] < arr[end]) {
            start = mid + 1;
        }
        // Ngược lại, tìm kiếm phía bên trái của mảng
        else {
            end = mid - 1;
        }
    }

    // Không tìm thấy phần tử nào đạt yêu cầu đa số, trả về -1
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        // Tìm phần tử đầu tiên bị lặp trong mảng và in kết quả ra màn hình
        int result = findMajorityElement(A);
        if (result != -1) {
            cout << result << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
