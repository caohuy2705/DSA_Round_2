#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        queue<long long> q;
        q.push(1);
        while(q.size()) {
            long long top = q.front();
            if(top % n == 0) {
                cout << top << endl;
                break;
            }
            q.pop();
            q.push(top*10);
            q.push(top*10+1);
        }
    }
}