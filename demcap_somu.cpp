#include <bits/stdc++.h>
using namespace std;
int cnt[5];
int count (int y[], int m, int x) {
	if (x==0) return 0;
	if (x==1) return cnt[0];
	long long res=cnt[0] + cnt[1];
	auto it = upper_bound(y, y+m, x);
	res +=(y+m)-it;
	if (x==2) res-=(cnt[4]+cnt[3]);
	if (x==3) res+=cnt[2];
	return res;
} 
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		for (int i=0; i<m; i++) {
			cin >> b[i];
			if (b[i] <= 4) cnt[b[i]] ++;
		};
		long long ans=0;
		sort(b,b+n)	;
		for (int x:a) {
			ans+=count (b,m,x);
		}
		cout << ans << endl;
		memset (cnt, 0, sizeof(cnt));
	}
}
