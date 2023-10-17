#include <bits/stdc++.h>
using namespace std;
string s1,s2;
string solve (string s) {
	stack <char> st;
	for (int i=0; i<s.size(); i++) {
		if (s[i]=='(') {
			if (s[i-1]=='+' || s[i-1]=='-') st.push(s[i-1]);
		}
		if (!st.empty() && st.top()=='-') {
			if (s[i]=='+') s[i]='-';
			else if (s[i]=='-') s[i]='+';
		}
		if (s[i]==')' && !st.empty()) st.pop();
	}
	string res="";
	for (int i=0; i<s.size(); i++) {
		if (s[i]!='(' && s[i]!=')') res+= s[i];
	}
	return res;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		if (solve(s1)==solve(s2)) cout <<"YES";
		else cout <<  "NO";
		cout << endl;
	}
}
