#include <bits/stdc++.h>
using namespace std;
long long n;
void solve1() {	
	queue <long long> q;
	q.push(1);
	int res=0;
	while (1) {
		long long top=q.front();
		if (top<=n) res++;
		else break;
		q.pop();
		q.push(top*10);
		q.push(top*10+1);
	}	
	cout << res << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		solve1();
	}
}
