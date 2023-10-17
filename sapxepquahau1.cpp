#include <bits/stdc++.h>
using namespace std;
int n, cot[100], d1[100], d2[100], a[100], dem;
void Try (int i) {
	for (int j=1; j<=n; j++) {  //for ( j =<kha nang 1>; j <=n; j++ ){
		if (cot[j] && d1[i-j+n] && d2[i+j-1]) {  // if (<chap nhan kha nang j>) 
			a[i]=j; // X[i] = <kha nang j>;
			cot[j] = d1[i-j+n] = d2[i+j-1] = 0;  // mang danh dau
			if (i==n) dem ++; // if ( i ==n) Result();
			else Try(i+1);   // else Back-Track(i+1);
			cot[j] = d1[i-j+n] = d2[i+j-1] = 1; // tra ve mang danh dau gia tri ban dau
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		dem=0;
		for (int i=1; i<=100; i++) cot[i]=d1[i]=d2[i]=1;
		Try(1);
		cout << dem << endl;
	}
}


