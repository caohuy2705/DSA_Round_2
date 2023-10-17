#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Hàm kiểm tra xem toán tử op1 có độ ưu tiên cao hơn toán tử op2 hay không
bool hasHigherPrecedence(char op1, char op2) {
    unordered_map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
    return precedence[op1] >= precedence[op2];
}

// Hàm chuyển đổi biểu thức trung tố sang hậu tố
string infixToPostfix(const string& expression) {
    stack<char> operators;
    string postfix;

    for (char ch : expression) {
        if (isalnum(ch)) {
            postfix += ch; // Ký tự ch là toán hạng, thêm vào biểu thức hậu tố
        } else if (ch == '(') {
            operators.push(ch); // Đưa dấu ngoặc mở vào ngăn xếp operators
        } else if (ch == ')') {
            // Đưa các toán tử trong ngăn xếp operators vào biểu thức hậu tố đến khi gặp dấu ngoặc đóng
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Loại bỏ dấu ngoặc mở ra khỏi ngăn xếp
        } else if (isOperator(ch)) {
            // Đưa các toán tử có độ ưu tiên cao hơn hoặc bằng ch vào biểu thức hậu tố
            while (!operators.empty() && hasHigherPrecedence(operators.top(), ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch); // Đưa toán tử ch vào ngăn xếp operators
        }
    }

    // Đưa các toán tử còn lại trong ngăn xếp vào biểu thức hậu tố
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Đọc ký tự newline sau số lượng bộ test

    while (T--) {
        string expression;
        getline(cin, expression);

        string postfix = infixToPostfix(expression);
        cout << postfix << endl;
    }

    return 0;
}
