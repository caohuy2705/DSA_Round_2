#include <bits/stdc++.h>
using namespace std;
int r, l;
int check (int n) {
	priority_queue <int> pq;
	while (n) {
		pq.push(n%10);
		n/=10;
	}
	int temp=0;
	if (pq.top() > 5) return 0;
	else {
		temp=pq.top();
		pq.pop();
	}
	while (!pq.empty()) {
		if (pq.top() > 5) return 0;
		if (pq.top()==temp) return 0;
		temp=pq.top();
		pq.pop();
	}
	return 1;
}
void solve () {
	int res=0;
	for (int i=l; i<=r; i++) {
		if (check(i)) res++;
	}
	cout << res << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> l >> r;
		solve();
	}
}
