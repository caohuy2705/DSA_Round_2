#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		stack <long long> st;
		long long res=0;
		int i=0;
		while (i<n) {
			if (st.empty() || a[i]>=a[st.top()]) {
				st.push (i);
				i++;
			} else {
				int idx=st.top();
				st.pop();
				if (st.empty()) {
					res=max(res, i*a[idx]);
				} else {
					res = max(res, a[idx]*(i-st.top()-1));
				}
			}	
		}
		while (!st.empty()) {
			int idx=st.top();
			st.pop();
			if (st.empty()) {
				res=max(res, i*a[idx]);
			} else {
				res = max(res, a[idx]*(i-st.top()-1));
			}
		}
		cout << res << endl;
	}
}
