#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    // Đọc xâu S
    string S;
    cin >> S;

    // Tạo bảng đếm số lần xuất hiện của mỗi ký tự
    unordered_map<char, int> freq;

    // Tính số lần xuất hiện của mỗi ký tự
    for (char ch : S) {
        freq[ch]++;
    }

    // Tìm số lần xuất hiện nhiều nhất (A) và ít nhất (B)
    int maxFreq = 0;
    int minFreq = N; // Giả sử mỗi ký tự xuất hiện ít nhất là N lần (không xuất hiện)

    for (const auto& entry : freq) {
        maxFreq = max(maxFreq, entry.second);
        minFreq = min(minFreq, entry.second);
    }

    // Tính chênh lệch cực đại và ghi kết quả
    int maxDiff = maxFreq - minFreq;
    cout << maxDiff << endl;

    return 0;
}
