#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> st;
    int n;
    cin >> n;
    string s;
    while(cin >> s) {
        if(s == "PUSH") {
            cin >> n;
            st.push(n);
        }
        else if(s == "POP" && st.size()) {
                st.pop();
            }
        else if(s == "PRINT") {
            if(st.size()) {
                cout << st.top() << endl;
            }
            else cout << "NONE" << endl;
        }
    }
}