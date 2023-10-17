#include <bits/stdc++.h>
using namespace std;
int n, a[11];
vector <vector<int>> res;
void solve(int n) {
	vector <int> temp;
	for (int i=1; i<=n; i++) temp.push_back(a[i]);
	res.push_back(temp);
}
void Try(int i, int sum, int k) {
	for (int j=k; j>0; j--) {
		if (sum+j<=n) {
			a[i]=j;
			if (sum+j==n) solve(i);
			else Try(i+1, sum+j, j);
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		res.clear();
		cin >> n;
		Try(1,0,n);
		cout << res.size() << endl;
		for (int i=0; i<res.size(); i++) {
			cout <<"(";
			for (int j=0; j<res[i].size()-1; j++) {
				cout << res[i][j]<< " ";
			}
			cout << res[i][res[i].size()-1] << ") ";
		}
		cout << endl;
	}
}
