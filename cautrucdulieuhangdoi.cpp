#include <bits/stdc++.h>
using namespace std;
main () {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		queue <int> q;
		while (n--) {
			int ask;
			cin >> ask;
			switch (ask) {
				case 1: cout << q.size () << endl;
						break;
				case 2: if (q.empty()) cout << "YES"; 
						else cout << " NO";
						cout << endl;
						break;
				case 3: int temp; 
						cin >> temp; q.push(temp); break;
				case 4: if (!q.empty()) q.pop(); break;
				case 5: if (q.empty()) cout << "-1" << endl;
						else cout << q.front() << endl; break;
				case 6: if (q.empty()) cout << "-1" << endl;
						else cout << q.back() << endl; 
						break;
			}
		}
	}
}
