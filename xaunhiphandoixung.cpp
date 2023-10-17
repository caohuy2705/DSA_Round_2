#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        string tmp;
        tmp = s;
        reverse(tmp.begin()+l-1, tmp.begin()+r);
        cout << tmp << " " << s << endl;
        if(tmp == s) {
            cout << "YES" << endl;
        } 
        else cout << "NO" << endl;
    }
}