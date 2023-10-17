#include <bits/stdc++.h>
using namespace std;
struct task {
	int start, finish;
} a[1005];
bool cmp ( task x, task y) {
	return x.finish > y.finish;
}
main () {
	int n, t, x;
	cin >> t;
	while (t--) {
		cin >> n;
		int check[1005]={0};
		for (int i=0; i<n; i++) {
			cin >> x >> a[i].start >> a[i].finish;
		}
		sort (a, a+n, cmp);
		int s=0, d=0;
		for (int i=0; i<n; i++) {
			for (int j=min(n, a[i].start); j>=1; j--) {
				if (!check[j]) {
					s+=a[i].finish;
					d++;
					check[j]=1;
					break;
				}
			}

		}
		cout << d << " " << s << endl;
	}
}
