#include <bits/stdc++.h>
using namespace std;
int k;
string s;
void solve () {
	int f[26];
	memset (f, 0, sizeof(f));
	for (int i=0; i<s.size(); i++) f[s[i]-'A'] ++;
	sort(f,f+26, greater<int>()); // sapxepgiamdan
	priority_queue <long long> p;
	long long res=0;
	for (int i=0; i<26; i++) p.push(f[i]);
	while (!p.empty()) {
		long long temp=p.top();
		if (k) {
			p.pop();
			p.push(temp-1);
			k--;
		}
		else {
			res+=temp*temp;
			p.pop();
		}
	}
	cout << res <<endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> k >> s;
		solve();
	}
}
