#include <bits/stdc++.h>
using namespace std;
int n, m, a[101][101], dem;
void Try (int i, int j) {
	if (i==n && j==m) {   // neu thoa man dieu kien dung
		dem++; // giai quyet truong hop suy bien
		return; 
	}
	if (i+1<=n) Try(i+1, j); // goi ham de quy neu thoa man dieu kien
	if (j+1<=m) Try(i, j+1); // // goi ham de quy neu thoa man dieu kien
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		dem=0;
		for (int i=1; i<=n ;i++)
			for (int j=1; j<=m; j++)
				cin >> a[i][j];
		Try(1,1);
		cout << dem << endl;
	}
}


