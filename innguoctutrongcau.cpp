#include <bits/stdc++.h> 
using namespace std;

/// mot hai ba bon nam sau bay tam
int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string token;
    stack<string> st;
    while(ss >> token) {
        st.push(token);
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}