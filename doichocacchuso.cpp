#include <bits/stdc++.h>
using namespace std;
main () {
	int t, k; 
	string s;
	cin >> t;
	while (t--) {
		cin >> k >> s;
		for (int i=0; i<k && i< s.size(); i++) {
			int MAX=i, j=s.size();
			while (j-->i) {
				if (s[j]>s[MAX]) MAX=j;
			}
			if (MAX!=i) swap(s[i],s[MAX]);
			else k++;
		}
		cout << s << endl;
	}
}
