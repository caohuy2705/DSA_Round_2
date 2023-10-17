#include <iostream>
#include <vector>
using namespace std;

// Hàm d? quy d? tìm dãy con tang dài nh?t k?t thúc t?i v? trí i
int longestIncreasingSubsequenceRecursive(vector<int>& A, int N, int i, int& max_length) {
    if (i == 0) {
        return 1;
    }

    int current_length = 1;

    for (int j = 0; j < i; ++j) {
        if (A[i] > A[j]) {
            int subsequence_length = longestIncreasingSubsequenceRecursive(A, N, j, max_length) + 1;
            current_length = max(current_length, subsequence_length);
        }
    }

    max_length = max(max_length, current_length);
    return current_length;
}

int longestIncreasingSubsequence(vector<int>& A, int N) {
    int max_length = 1;
    longestIncreasingSubsequenceRecursive(A, N, N - 1, max_length);
    return max_length;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int result = longestIncreasingSubsequence(A, N);
    cout << result << endl;

    return 0;
}
