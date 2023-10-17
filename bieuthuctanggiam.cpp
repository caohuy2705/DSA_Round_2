#include <bits/stdc++.h>
using namespace std;
string s;
void solve () {
	s=' '+s;
	stack <int> st;
	for (int i=1; i<=s.size(); i++) {
		if (s[i]=='D') st.push(i);
		else {
			cout << i; 
			while (!st.empty()){
				cout << st.top();
				st.pop();
			}
		}
	}
	cout << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		solve();
	}
}
