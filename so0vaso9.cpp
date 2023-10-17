#include <bits/stdc++.h>
using namespace std;
long long n;
void solve1() {	
	queue <long long> q;
	q.push(9);
	while (1) {
		if (q.front()%n==0) {
			cout << q.front();
			break;
		} else {
			q.push(q.front()*10);
			q.push(q.front()*10+9);	
			q.pop();
		}
	}	
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		solve1();
		cout << endl;
	}
}
