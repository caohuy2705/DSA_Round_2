#include <bits/stdc++.h>
using namespace std;

string n, top;

bool check(string s) {
    return s.size() < n.size() || (s.size() == n.size() && s <= n);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int cnt = 0;
        cin >> n;
        stack<string> st;
        st.push("1");
        while(st.size()) {
            top = st.top();
            cnt++;
            st.pop();
            if(check(top+"0"))    
                st.push(top + "0");
            if(check(top + "1"))  
                st.push(top + "1");
        }
        cout << cnt << endl;
    }
}
