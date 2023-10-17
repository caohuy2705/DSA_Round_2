#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        int left_num = 1;
        stack<int> right_num;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                cout << left_num << " ";
                right_num.push(left_num);
                left_num++;
            }
        else if(s[i] == ')') {
            cout << right_num.top() << " ";
            right_num.pop();
        }
        }
        cout << endl;
    }
}