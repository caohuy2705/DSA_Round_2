#include <bits/stdc++.h>
using namespace std;

int n, ck = 0, b[25] = {0};
int checkRev(int a[], int n){
	int d = 1, c = n;
	while (d < c){
		if (a[d] != a[c]) 
			return 0;
		d++;
		c--;
	}
    return 1;
}
void output() {
	if (checkRev(b, n)) {
		for (int i = 1; i <= n; i++) 
        cout << b[i] << " ";
		cout << endl;
	}
}
void generate() {
	int i=n;
	while (b[i]) {
		b[i] = 0; 
		i--;
	}
	if (i == 0) 
        ck = 1;
	else b[i]=1;
}
main () {
	cin >> n;
	while (!ck) {
		output();
		generate();
	}
}
