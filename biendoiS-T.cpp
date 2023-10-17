#include <bits/stdc++.h>
using namespace std;
int s, t; 
int solve () {
	queue <pair <int,int>> q;
	set <int> se;
	se.insert(s);
	q.push({s,0});
	while (!q.empty()) {
		pair <int,int> top=q.front();
		q.pop();
		if (top.first==t) return top.second;
		if (top.first*2==t || top.first-1==t) return top.second+1;
		if (se.find(top.first*2)==se.end() && top.first<t) {
			q.push({top.first*2, top.second+1});
			se.insert(top.first*2);
		}
		if (se.find(top.first-1)==se.end() && top.first>1) {
			q.push({top.first-1, top.second+1});
			se.insert(top.first-1);
		}
	}
}
main () {
	int T;
	cin >> T;
	while (T--) {
		cin >> s >> t;
		cout << solve() << endl;
	}
}
