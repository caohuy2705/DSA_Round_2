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
        if(s == "PUSHFRONT") {
            cin >> x;
            q.push_front(x);
        }
        else if(s == "PRINTFRONT") {
            if(q.size()) {
                cout << q.front() << endl;
            } else cout << "NONE" << endl;
        }
        else if(s == "POPFRONT") {
            if(q.size())
                q.pop_front();
        }
        else if(s == "PUSHBACK") {
            cin >> x;
            q.push_back(x);
        }
        else if(s == "PRINTBACK") {
            if(q.size()) 
                cout << q.back() << endl;
            else cout << "NONE" << endl;
        }
        else if(s == "POPBACK") {
            if(q.size()) 
                q.pop_back();
        }
    }
}