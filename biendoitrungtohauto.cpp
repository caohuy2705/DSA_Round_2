#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(const string& expression) {
    string result;
    stack<char> st;

    for (char ch : expression) {
        if (isalnum(ch))
            result += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // Xóa d?u '(' kh?i stack
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    cin.ignore(); // Xóa d?u newline sau khi d?c T

    while (T--) {
        string exp;
        getline(cin, exp); // Nh?p bi?u th?c trung t?

        string postfix_exp = infixToPostfix(exp);
        cout << postfix_exp << endl;
    }

    return 0;
}

