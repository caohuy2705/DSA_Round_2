#include <bits/stdc++.h>
using namespace std;
int n;
//vector <string> v;
//void solve() {
//	
//	queue <string> q;
//	q.push("1");
//	v.push_back("1");
//	while (v.size()<10000) {
//		string top=q.front();
//		v.push_back(top+"0");
//		v.push_back(top+"1");
//		q.pop();
//		q.push(top+"0");
//		q.push(top+"1");
//	}
//	for (int i=0; i<n; i++) cout << v[i] << " ";
//	
//}
void solve1() {	
	queue <string> q;
	q.push("1");
	for (int i=1; i<=n; i++) {
		string top=q.front();
		cout << top << " ";
		q.pop();
		q.push(top+"0");
		q.push(top+"1");
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
