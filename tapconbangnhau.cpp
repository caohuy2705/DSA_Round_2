#include <bits/stdc++.h>
using namespace std;
int sum, n, a[105];
string OK;
void Try(int i, int cursum) {
	if (OK=="YES") return;
	if (2*cursum==sum) {
		OK="YES";
		return;
	}
	if (i<n) {
		if (2*(cursum + a[i])<= sum) Try(i+1, cursum+a[i]);
		Try(i+1, cursum);
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		OK="NO";
		sum=0;
		for (int i=1; i<=n; i++ ) {
			cin >> a[i];
			sum+=a[i];
		}
		if (sum % 2 == 0) Try(0,0);
		cout << OK << endl;	
	}
}
