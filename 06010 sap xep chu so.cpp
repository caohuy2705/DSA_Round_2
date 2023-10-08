#include <bits/stdc++.h>
using namespace std;
int main () {
	int t, n;
	string a[100];
	cin >> t;
	while (t--) {
		int b[100]={};
		cin >> n;
		int i, j;
		for (i=0; i<n; i++) cin >> a[i];
		for (i=0; i<n; i++) {
			for (j=0; j< a[i].size(); j++) {
				b[a[i][j]-'0'] ++;
			}
		}
		for (i=0; i<10; i++) {
			if (b[i]>0) cout << i << " ";
		}
		cout << endl;
	}
}
