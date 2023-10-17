#include <bits/stdc++.h>
using namespace std;
main () {
	int Q;
	cin >> Q;
	cin.ignore();
	queue <int> q;
	while (Q--) {
		string s;
		cin >> s;
		if (s=="PUSH") {
			int n;
			cin >> n;
			q.push(n);
		}
		if (s=="POP") {
			if (!q.empty()) q.pop();
		}
		if (s== "PRINTFRONT") {
			if (!q.empty()) cout << q.front() << endl;
			else cout << "NONE" << endl;
		}
	}
}
