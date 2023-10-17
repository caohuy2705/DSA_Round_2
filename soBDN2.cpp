#include <bits/stdc++.h>
using namespace std;
int n;
void solve1() {	
	queue <long long> q;
	q.push(1);
	while (1) {
		long long top=q.front();
		if (top%n==0) {
			cout << top << endl;
			break;
		}
		q.pop();
		q.push(top*10);
		q.push(top*10+1);
	}	
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		solve1();
	}
}
