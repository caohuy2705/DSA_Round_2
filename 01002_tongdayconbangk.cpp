#include <bits/stdc++.h>
using namespace std;
int n, k, C[1000];
void in () {
		for (int i=1; i<=k; i++) cout << C[i] << " " ;

}
void sinh () {
	int i, j;
	i=k;
	while (C[i]==n-k+i) i--;
	if (i == 0 ) {
		for (j=1; j<=k; j++) C[j]=C[j-1]+1;
	}
	else {
		C[i]++;
		for (j=i+1; j<=k; j++) C[j]=C[j-1]+1;
	}
}

main () {
	int t,i;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=1; i<=k; i++)  cin >> C[i];
		sinh ();
		in();
		cout << endl;		
	}
}
