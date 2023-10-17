#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluate(int operand1, int operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0;
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        int n;
        cin >> n;
        cin.ignore(); // Ignore the newline character after n
        string s;
        getline(cin, s);
        stack<int> operands;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isdigit(s[i]) || (s[i] == '-' && (i == 0 || isOperator(s[i - 1])))) {
                int operand = 0;
                int multiplier = 1;
                int sign = 1;
                if (s[i] == '-') {
                    sign = -1;
                    i--;
                }
                while (i >= 0 && isdigit(s[i])) {
                    operand += (s[i] - '0') * multiplier;
                    multiplier *= 10;
                    i--;
                }
                operands.push(sign * operand);
            } else if (isOperator(s[i])) {
                int operand1 = operands.top();
                operands.pop();
                int operand2 = operands.top();
                operands.pop();
                int result = evaluate(operand1, operand2, s[i]);
                operands.push(result);
            }
        }
        cout << operands.top() << endl;
    }
    return 0;
}
