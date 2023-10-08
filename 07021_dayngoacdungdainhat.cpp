#include <iostream>
#include <stack>
#include <string>
using namespace std;

int findLongestValidParentheses(const string& s) {
    int n = s.length();
    stack<int> stk;
    stk.push(-1); // Đặt một phần tử giả vào stack để tính toán độ dài hiện tại

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push(i); // Đưa chỉ số vào stack khi gặp dấu '('
        } else {
            stk.pop(); // Loại bỏ dấu '(' trước đó
            if (!stk.empty()) {
                maxLen = max(maxLen, i - stk.top()); // Tính toán độ dài của dãy ngoặc đúng hiện tại
            } else {
                stk.push(i); // Đặt một phần tử giả vào stack để tính toán độ dài tiếp theo
            }
        }
    }

    return maxLen;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        int result = findLongestValidParentheses(S);
        cout << result << endl;
    }

    return 0;
}
