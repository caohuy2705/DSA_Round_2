#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, i;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        i = s.size()-1; 
        while(i >= 0 && s[i] == '0') {
            s[i] = '1';
            i--;
        }
        if(i >= 0) 
            s[i] = '0';
            cout << s << endl;
    }
}