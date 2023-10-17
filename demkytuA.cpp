#include <bits/stdc++.h>
using namespace std;

int calc(string c, string a, string b) {
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
        vector<string> s(n);
        for(int i = 0; i < n; i++)  
            cin >> s[i];
        stack<string> st;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == "*" || s[i] == "/" || s[i] == "+" s[i] == "-")
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                st.push(calc(string(c, a, b));
        } else st.push(s[i]);
    cout << st.top() << endl;
    }
}