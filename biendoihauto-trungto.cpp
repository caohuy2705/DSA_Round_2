#include <bits/stdc++.h>
using namespace std;
string s;
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void solve() {
	stack <string> st;
	for (int i=0; i<s.size(); i++) {
		if (!is_operator(s[i])) st.push(string(1,s[i]));
		else {
			string s1=st.top(); st.pop();
			string s2=st.top(); st.pop();
			string temp="(" + s2 + s[i] + s1 + ")";
			st.push(temp);
		}
	}
	cout << st.top() << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		solve();
	}
}


//(A+B)
//(C-D)
//temp=(A+B)
//s1=C
//s2=D
//A
//B

