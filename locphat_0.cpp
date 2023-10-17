#include <bits/stdc++.h>

using namespace std;
/*
vector<int> res;
check rev(string s, int n) {
    for(int i = 1; i <= s.size(); i++) {
        int d = 1;
        int c = n;
        for(while d < c) {
            if(s[d] != s[c]) 
                return 0;
        }
    return 1;
    }
}*/ 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<string> dq;
        stack<string> ans;
        dq.push("6");
        dq.push("8");
        
            while (dq.size())
            {
                string top = dq.front();
                ans.push(top);
                dq.pop();
                if (top.size() != n)
                {
                    dq.push(top + "6");
                    dq.push(top + "8");
                }
            }
            for(int i = 0; i <= n; i++) {
                cout << ans.top() << " ";
                ans.pop();
            }
            /* while (ans.size())
            {
                cout << ans.top() << " ";
                ans.pop();
            }
            cout << endl; */
        
    }
}









