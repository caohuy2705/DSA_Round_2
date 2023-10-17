#include <bits/stdc++.h>
using namespace std;
main(){
    int Q,x;
    cin >> Q;
    string s;
    deque<int> dq;
    while (Q--) {
        cin >> s;
        if (s == "PUSHFRONT") {
            cin >> x;
            dq.push_front(x);
        }
        else if (s == "PRINTFRONT") {
            if (!dq.empty())
                cout << dq.front() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POPFRONT") {
            if (!dq.empty())
                dq.pop_front();
        }
        else if (s == "PUSHBACK") {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "PRINTBACK") {
            if (!dq.empty())
                cout << dq.back() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POPBACK") {
            if (!dq.empty())
                dq.pop_back();
        }
    }
}
