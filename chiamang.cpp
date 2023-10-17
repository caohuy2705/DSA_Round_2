#include <bits/stdc++.h>
using namespace std;
int n, k, a[21], sum, check[21], OK;
void Try (int cursum, int count) {
	if (count==k) {
		OK=1;
		return;
	}
	if (OK) return;
	for (int j=1; j<=n; j++) {
		if (!check[j]) {
			check[j]=1;
			if (cursum==sum) Try(0,count+1);
			else if (cursum<sum) Try(cursum+a[j],count);
				else return;
		}
		check[j]=0;
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		OK=0, sum=0;
		for (int i=1; i<=n; i++) {
			cin >> a[i];
			sum+=a[i];
		}
		if (sum%k!=0) cout << OK << endl; 
		else {
			sum/=k;
			Try(0,0);
			cout << OK << endl;
		}	
	}
}
