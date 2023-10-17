#include <bits/stdc++.h>

using namespace std;
/* 
int checkrev(string s, int s.length()) {
    if(s.length() >= 2 && s.length() %2==0) {
    for(int i = 1; i <= s.size(); i++) {
        int d = 1;
        int c = s.length();
        while (d < c) {
            if(s[d] != s[c]) 
                return 0;
        }
    }
    }
    return 1;
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
        int i = n;
        while (dq.size() /*&& i >= 1*/) {
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
        }
            /*
            for(int i = 0; i <= n; i++) {
                cout << ans.top() << " ";
                ans.pop();
            }*/ 
            while (ans.size()) {
                string tmp = ans.top();
                 if(tmp.length() >= 2) {
                    for(int i = 1; i <= tmp.length(); i++) {
                        int d = 1;
                        int c = tmp.length();
                        while (d < c) {
                            if(tmp[d] != tmp[c]) {
                                break;
                            cout << ans.top() << " ";
                            ans.pop();
                            }
                        }
                        
                    }
                    }
                    //cout << ans.top() << " ";
                    //ans.pop();
                
            }
            cout << endl; 
        //i--;
    }
}









