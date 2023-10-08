#include <bits/stdc++.h>
using namespace std;

int solve(int s, int t) {
    queue<pair<int, int>> q;
    set<int> se;
    se.insert(s);
    q.push({s, 0});
    while(!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        if(top.first == t) //so thu nhat trong pair (gia tri)
            return top.second; //so thu hai trong pair (so buoc)
        if(top.first*2 == t || top.first-1 == t) 
            return top.second+1; //them 1 thao tac
        if(se.find(top.first*2) == se.end() && top.first < t) {
            q.push({top.first*2, top.second+1});
            se.insert(top.first*2);
        }
        if(se.find(top.first-1) == se.end() && top.first > 1) {
            q.push({top.first-1, top.second+1});
            se.insert(top.first-1);
        }
    }
}

int main() {
    int n; cin >> n;
    while(n--) {
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }
}