#include <bits/stdc++.h>
using namespace std;
char c;
int k, n, A[30];
void in () {
	for (int i=1; i<=k; i++) cout << (char) (A[i]+ 64);
	cout << endl;
}
void Try(int i, int x) {
	for (int j=x; j<=n; j++) {
		A[i]=j;
		if (i==k) in();
		else Try(i+1, j);
	}
}
main () {
	cin >> c >> k;
	n = (int)c -'A'+1;
	Try(1,1);
}
