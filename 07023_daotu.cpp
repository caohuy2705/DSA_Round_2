#include <bits/stdc++.h>
using namespace std;

string reverse(string s) {
    stack<string> st;
    stringstream ss(s);
    string word;
    while(ss >> word) {
        st.push(word);
    }
    string reversed;
    while(!st.empty()) {
        reversed += st.top() + " ";
        st.pop();
    }
    if(!reversed.empty()) {
        reversed.pop_back();
    }
    return reversed;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        cout << reverse(s) << endl;
    }
}
