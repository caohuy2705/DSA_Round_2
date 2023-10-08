#include <bits/stdc++.h> 
using namespace std;
void sapxep(int a[], int n){
    int i,j,t;
    for(i=0; i<n; i++){
        t=a[i]; j=i-1;
        while(a[j]>t && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }
}
main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n; 
		string x;
		int b[10]={}, a[10], k=0;
		for (int i=0; i<n; i++) {
			cin >> x;
			for (int j=0; j<x.size(); j++) {
				if (b[x[j] -'0']==0) a[k++] = x[j]-'0';
				b[x[j]-'0']++;
			}
		}
		sapxep(a, k);
		for (int i=0; i<k ;i++) cout << a[i] << " ";
		cout << endl;
	}
}