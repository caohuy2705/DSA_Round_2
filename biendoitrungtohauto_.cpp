#include <bits/stdc++.h>
using namespace std;
string s;
int check(char c) {
	if (c=='+'|| c=='-') return 1;
	if (c=='*'|| c=='/') return 2;
	if (c=='^') return 3;
	return 0;
}
void solve () {
	stack <char> st;
	string res="";
	for (int i=0; i<s.size(); i++) {
		if (isalpha(s[i])) res+=s[i];
		else if (s[i]=='(') st.push(s[i]);
		else if (s[i]==')') {
			while (!st.empty() && st.top()!='(') {
				res+=st.top();
				st.pop();
			}
			st.pop();
		} else {
			while (!st.empty() && check(st.top())>=check(s[i])) {
				res +=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty()) {
		if (st.top()!='(') res+=st.top();
		st.pop();
	}
	cout << res << endl;
}
main () {
	int t;
	cin >> t;
	 while (t--) {
	 	cin >> s;
	 	solve();
	 }
}
