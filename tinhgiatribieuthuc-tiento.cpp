#include <bits/stdc++.h>
using namespace std;
string s;
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int cal (int a, int b, char x) {
	if (x=='+') return a+b;
	if (x=='-') return a-b;
	if (x=='*') return a*b;
	if (x=='/') return a/b;
}
void solve() {
	stack <int> st;
	for (int i=s.size(); i>=0; i--) {
		if (!is_operator(s[i])) st.push(s[i]-'0');
		else {
			int s1=st.top(); st.pop();
			int s2=st.top(); st.pop();
			int temp= cal(s1,s2, s[i]);
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
