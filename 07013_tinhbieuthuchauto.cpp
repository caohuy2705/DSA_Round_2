#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

string ts = "+-*/";
bool check(char c)
{
    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return (c >= '1' && c <= '9');
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin>> s;
        int st[s.size()] = {};
        int p = -1;
        for(int i = 0; i < s.size(); i++) {
            if(Var(s[i]))
                st[++p] = s[i] - '0';
            if(s[i] == '*') {
                st[p-1]*=st[p];
                p--;
                continue;
            }
            if(s[i] == '/') {
                st[p-1] /= st[p];
                p--;
                continue;
            }
            if(s[i] == '+') {
                st[p-1] += st[p];
                p--;
                continue;
            }
            if(s[i] == '-') {
                st[p-1] -= st[p];
                p--;
                continue;
            }
        }
        cout << st[0] << endl;
        }
}

/*
2
231*+9–
875*+9-
*/