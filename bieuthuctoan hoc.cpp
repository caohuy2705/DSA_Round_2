#include <bits/stdc++.h>
using namespace std;
int a[101], OK, B[101];
void Try (int i, int s) {
	if (OK) return;
	if (s==23 && i==5) {
		OK=1;
		return;
	}
	for (int j=0; j<5; j++) {
		if (!B[j]) {
			B[j]=1;
			Try(i+1, s*a[j]);
			Try(i+1, s+a[j]);
			Try(i+1, s-a[j]);
			B[j]=0;
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		for (int i=0; i<5; i++) cin >> a[i];
		OK=0;
		for (int i=0; i<5; i++) {
			B[i]=1;
			Try(1,a[i]);
			B[i]=0;
		}
		if (OK) cout << "YES";
		else cout << "NO";
		cout <<endl;
	}
}
