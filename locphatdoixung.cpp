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
            string k = dq.front();
            ans.push(k);
            dq.pop();
            if (k.size() != n)
            {
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        while (ans.size())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
}








