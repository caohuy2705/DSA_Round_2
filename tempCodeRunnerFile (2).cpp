#include<bits/stdc++.h>

using namespace std;

int calc(string &s)
{
    stack<char> st;
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for(char &i : s)
    {
        if(i == ')' and st.size() and st.top() == '(') st.pop();
        else st.push(i);
    }
    while(st.size())
    {
        if(st.top() == '(') ++cnt1;
        else ++cnt2;
        st.pop();
    }
    return (cnt1 >> 1) + (cnt1 & 1) + (cnt2 >> 1) + (cnt2 & 1);
}

int main()
{
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        cout << calc(s) << endl;
    }
    return 0;
}