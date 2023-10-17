#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int longest = 0;
    for (int i = 0; i < n; ++i) {
        longest = max(longest, dp[i]);
    }

    return longest;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = longestIncreasingSubsequence(arr);
    cout << result << endl;

    return 0;
}
