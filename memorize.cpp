#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        getline(cin, s);
        int num_left = 1;
        stack<int> num_right;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                cout << num_left << " ";
                num_right.push(num_left);
                num_left++;
            }
            else if(s[i] == ')') {
                cout << num_right.top() << " ";
                num_right.pop();
            }

        }
        cout << endl;
    }
}
