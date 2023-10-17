#include <bits/stdc++.h>
using namespace std;
int n, OK, k, C[35], A[1000];
void in () {
		for (int i=1; i<=k; i++) cout << A[C[i]] << " ";
		cout << endl;
}
void sinh (int m) {
	int i, j;
	i=k;
	while (C[i]==m-k+i) i--;
	if (i == 0 ) OK=1;
	else {
		C[i]++;
		for (j=i+1; j<=k; j++) C[j]=C[j-1]+1;
	}
}
main () {
	int  i,j=0; 
	set <int> s;
	cin >> n >> k; OK=0;
	for (i=1; i<=n; i++){
		cin >> A[i];
		s.insert(A[i]);
	}
	for (i=1; i<=k; i++) {
		C[i]=i;	
	}
	for (int x:s) {
		j++;
		A[j]= x;
	}
	while (!OK) {
		in();
		sinh (j);	
	}
}
