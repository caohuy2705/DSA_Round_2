#include <bits/stdc++.h>
using namespace std;
int n, k, s, res, a[21], check[21];
void Try(int i, int sum) {
	for (int j=a[i-1]+1; j<=n-k+i; j++) {
		if (!check[j]) {
			check[j]=1;
			a[i]=j;
			sum+=a[i];
			if (i==k) {
				if (sum==s) res++;
			}
			else Try(i+1, sum);
			check[j]=0;
			sum-=a[i];
		}
	}
}
main () {
	while (1) {
		res=0;
		cin >> n >> k >> s;
		if (n==0 && k==0 && s==0) return 0;
		else Try(1,0);
		cout << res << endl;
	}
}
