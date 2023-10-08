#include <bits/stdc++.h>
using namespace std;
int A[25], C[25], x, n, OK;
void in(int m) {
	cout << "[";
	for (int i=1; i<m; i++) cout << C[i] << " ";
	cout << C[m] << "]";
}
void quaylui (int i, int s) {
	int j;
	for (j=1; j<=n; j++) {
		if (A[j]>=C[i-1] && s+A[j]<=x) {
			C[i]=A[j];
			s=s+A[j];
			if (s==x) {
				OK=1; in(i);
			}
			else quaylui (i+1, s);
			s=s-A[j];
		}
	}
}
main () {
	int t, i;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		for (i=1; i<=n; i++) cin >> A[i];
		C[0]=0; OK=0;
		quaylui (1,0);
		if (!OK) cout << "-1";
		cout << endl;
	}
}