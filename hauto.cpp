#include <bits/stdc++.h>
using namespace std;

string calc(string c, string a, string b) {
    long long x = stoll(a);
    long long y = stoll(b);
    if(c == "*")
        return to_string(x*y);
    if(c == "/")
        return to_string(x/y);
    if(c == "+")
        return to_string(x+y);
    if(c == "-") 
        return to_string(x-y);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> S(n);
        for(int i = 0; i < n; i++) 
            cin >> S[i];
        stack<string> X;
        for(int i = 0; i < n; i++) {
            if(S[i] == "*" || S[i] == "/" || S[i] == "+" || S[i] == "-") {
                string a = X.top();
                X.pop();
                string b = X.top();
                X.pop();
                X.push(calc(S[i], b, a)); // Đảo vị trí toán hạng trong phép tính
            }
            else X.push(S[i]);
        }
        cout << X.top() << endl;
    }
}
