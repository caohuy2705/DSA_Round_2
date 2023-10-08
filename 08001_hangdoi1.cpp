#include <bits/stdc++.h> 
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        deque<int> q;
        while(n--) {
            cin >> x;
            if(x == 1) {
                cout << q.size() << endl;
            }
            else if(x == 2) {
                if(q.empty()) {
                    cout << "YES" << endl;
                }
                else cout << "NO" << endl;
            }
            else if(x == 3) {
                cin >> x;
                q.push_back(x);
            }
            else if(x == 4) {
                if(q.size()) 
                    q.pop_front();
            }
            else if(x == 5) {
                if(q.size()) 
                    cout << q.front() << endl;
                else cout << -1 << endl;
            }   
            else if( x == 6) {
                if(q.size()) 
                    cout << q.back() << endl;
                else cout << -1 << endl;
            }
        }
    }
}