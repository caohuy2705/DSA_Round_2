#include <bits/stdc++.h>
using namespace std;
string s;
int solve() {
    stack <char> st;
	for (char x: s) {
		if (x=='(' || x=='{'|| x=='[') st.push(x);
		else {
			if (x==')') {
				if (!st.empty() && st.top()=='(') {
					st.pop();
				}
				else {
					return 0;
				}
			}
			else if (x==']') {
				if (!st.empty() && st.top()=='[') {
					st.pop();
				}
				else {
					return 0;
				}
			} else {
				if (!st.empty() && st.top()=='{') {
					st.pop();
				}
				else {
					return 0;
				}
			}			
		}
	}
	if (!st.empty()) return 0;
	return 1;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		if (solve()) cout << "YES"; else cout << "NO";
		cout << endl;
	}
}
