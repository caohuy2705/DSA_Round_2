#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> q;
    int x;
    string s;
    while(n--) {
        cin >> s;
        if(s == "PUSH") {
            cin >> x;
            q.push_back(x);
        }
        else if(s == "PRINTFRONT") {
            if(q.size()) {
                cout << q.front() << endl;
            } else cout << "NONE" << endl;
        }
        else if(s == "POP") {
            if(q.size())
                q.pop_front();
        }
    }
}