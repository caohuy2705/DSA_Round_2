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
        for(int i = 0; i < n; i++) {
            cin >> S[i];
        }
        stack<string> st;
        for(int i = n-1; i >= 0; i--) {
            if(S[i] == "*" || S[i] == "/" || S[i] == "+" || S[i] == "-") {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                st.push(calc(S[i], a, b));
            }
            else st.push(S[i]);
        }
        cout << st.top() << endl;
    }
}