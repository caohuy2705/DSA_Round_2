#include <bits/stdc++.h>
using namespace std;
stack <int> s;
string st;
int n;
void show() {
	stack <int> p=s;
	vector <int> a;
	while (!p.empty()) {
		a.push_back(p.top());
		p.pop();
	}
	for (int i=a.size()-1; i>=0; i--) cout << a[i] << " ";
	cout <<endl;
}
main () {
	while (1) {
		cin >> st;
		if (st=="push") {
			cin >> n; 
			s.push(n);
		}
		else if (st=="pop") s.pop();
		else if (st=="show") show();
		if (s.size()==0) {
			cout << "empty";
			break;
		}
	}
}
