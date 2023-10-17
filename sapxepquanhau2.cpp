#include <bits/stdc++.h>
using namespace std;
int MAX, dem, a[100], A[100][100], d1[100], cot[100], d2[100];
void solve () {
	dem=0;
	for (int i=1; i<=8; i++) dem+=A[i][a[i]];
	MAX=max(dem, MAX);
}
void Try(int i){
	for (int j=1; j<=8; j++) {
		if (cot[j] && d1[j] && d2[j]) {
			a[i]=j;
			cot[j]=d1[i-j+8]=d2[i+j-1]=0;
			if (i==8) solve();
			else Try(i+1);
			cot[j]=d1[i-j+8]=d2[i+j-1]=1;
		}	
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		MAX=0;
		for (int i=1; i<=8; i++)
			for (int j=1; j<=8; j++)
				cin >> A[i][j];
		for (int i=1; i<=100; i++) cot[i]=d1[i]=d2[i]=1;
		Try(1);
		cout << MAX << endl;
	}
}
