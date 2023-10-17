#include <bits/stdc++.h>
using namespace std;
int n, p[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
long long res;
void Try(int i, long long ali, long long temp) {
	if (ali>n) return;
	if (ali==n) res=min(temp,res);
	for (int j=1;; j++) {
		if (temp*p[i]>res) break;
		temp*=p[i];
		Try (i+1, ali*(j+1), temp);
	}
}
main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		res=1e18;
		Try(0,1,1);
		cout << res << endl;
	}
}
