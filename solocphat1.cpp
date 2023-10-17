#include <bits/stdc++.h>
using namespace std;
int n;
void solve1() {	
	vector <string> v;
	queue <string> q;
	q.push("6");
	q.push("8");
	while (1) {
		string top=q.front();
		v.push_back(top);
		q.pop();
		if (top.size() <n) {
			q.push(top+"6");
			q.push(top+"8");
		}
		else break;
	}	
	while (q.size()) {
		v.push_back(q.front());
		q.pop();
	}
	for (int i=v.size()-1; i>=0; i--) cout << v[i] << " ";
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
