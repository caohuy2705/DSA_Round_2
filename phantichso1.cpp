#include <bits/stdc++.h> 
using namespace std;
int n, a[11];
void in (int m) {
	cout << "(";
	for (int i=1; i<m; i++) cout << a[i] << " ";
	cout << a[m] << ") ";
}
void Try(int i, int k, int sum) {
	for (int j=k; j>=1; j--) { //for ( j =<kha nang 1>; j <=n; j++ ){
		if (sum+j<=n) {       // if (<chap nhan kha nang j>) 
			a[i]=j;			// X[i] = <kha nang j>;
			if (sum+j==n) in(i);  // if ( i ==n) Result();
			else Try(i+1, j, sum+j); // else Back-Track(i+1);
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		Try(1,n,0);
		cout << endl;
	}
}


