#include <bits/stdc++.h>
using namespace std;

int length(int a[], int n, int vitri, int k) {
	int count = 0;
	int len = 0;
	for(int i = vitri; i > 0; i--) {
		if(a[i] <= k)
			count += 1;
		else {
			len = max(len, count);
			count = 0;
		}
	}
	if(count) {
		len = max(len, count);
	}
	cout << len << " ";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n]; 
		for(int i = 0; i < n; i++) 
			cin >> a[i];
		for(int i = 0; i < n; i++) 
			length(a, n, i, a[i]);
		}
}




