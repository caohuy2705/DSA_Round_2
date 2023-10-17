#include <bits/stdc++.h> 
using namespace std;
int n, x, OK, a[100], b[100];
vector <vector <int>> res;
void solve (int n) {
	vector <int> temp;
	for (int i=1; i<n; i++) temp.push_back(b[i]);
	res.push_back (temp);
}
void Try(int i, int sum, int cur) {
	if (sum==x) {
		solve(i);
		OK=1;
		return;
	}
	for (int j=cur; j<=n; j++) {
		sum+=a[j];
		b[i]=a[j];
		if (sum<=x) Try(i+1, sum, j);
		sum-=a[j];
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		res.clear();
		cin >> n >> x;
		for (int i=1; i<=n; i++) cin >> a[i];
		OK=0;
		sort (a+1, a+n+1);
		Try(1,0,1);
		if (!OK) cout << "-1";
		else {
		    cout << res.size() << " ";
    		for (int i=0; i<res.size(); i++) {
    			cout << "{";
    			for (int j=0; j < res[i].size()-1; j++) {
    				cout << res[i][j] << " ";
    			}
    			cout << res[i][res[i].size()-1] << "} ";
    		}
		}
		cout << endl;
	}
}
