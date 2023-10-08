#include <bits/stdc++.h> 
using namespace std;
void sapxep(int a[],int n){
    int i,j,m,t;
    for(i=0;i<n-1;i++){
        m=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[m]) m = j;
        t=a[m]; a[m]=a[i]; a[i]=t;
    }
}
main () {
	int t;
	cin >> t;
	while (t--) {
		int n,d=0;
		cin >> n; 
		string x;
		int b[10]={};
		for (int i=0; i<n; i++) {
			cin >> x;
			for (int j=0; j<x.size(); j++) {
				a[d++] = x[j]-'0';
				b[x[j]-'0']++;
			}
		}
		sapxep(a, a+d);
		for (int i=0; i<d; i++) if (b[i]==1) cout << a[i] << " ";
		cout << endl;
	}
}