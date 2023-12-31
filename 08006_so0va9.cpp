#include <bits/stdc++.h>
using namespace std;

vector<long long> res;
long long ans[101];

void init() {
    queue<string> q;
    q.push("9");
    res.push_back(9);
    while(1) {
        string top = q.front();
        q.pop();
        if(top.length() == 10) 
            break;
        res.push_back(stoll(top + "0"));
        res.push_back(stoll(top + "9"));
        q.push(top + "0");
        q.push(top + "9");
    }
    for(int i = 1; i <= 100; i++) {
        for(long long x : res) {
            if(x % i == 0) {
                ans[i] = x;
                //++cnt;
                break;
            }
        }
    }
}

int main() {
    init();
    int t;
    cin >> t;
    while(t--) {
        int n; cin>> n;
        cout << ans[n] << endl;
    }
}