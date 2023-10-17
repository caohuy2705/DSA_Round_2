#include <bits/stdc++.h>
using namespace std;
int n, C[20][20], B[20], A[20],cmin=1e9, fopt=1e9, cost;
void Try(int i) {
	for (int j=2; j<=n; j++) {
		if (!B[j]) {
			B[j]=1;
			A[i]=j;
			cost+= C[A[i-1]][A[i]];
			if (i==n) {
				int v=cost+C[A[n]][A[1]];
				fopt=min(v,fopt);
			}
			else if (cost+cmin*(n-i+1) < fopt) Try(i+1);
			B[j]=0;
			cost-=C[A[i-1]][A[i]];
		}
		
	}
}
main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> C[i][j];
			if (i!=j) cmin=min(cmin, C[i][j]);
		}
	}
	A[1]=1;
	Try(2);
	cout << fopt;
}
