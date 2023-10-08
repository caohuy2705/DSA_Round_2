#include <bits/stdc++.h>

using namespace std;

bool Var(char c)
{
    return (c >= '1' && c <= '9');
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        stack<int> st;

        for (char c : s)
        {
            if (Var(c))
            {
                st.push(c - '0');
            }
            else
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                if (c == '*')
                {
                    st.push(op1 * op2);
                }
                else if (c == '/')
                {
                    st.push(op1 / op2);
                }
                else if (c == '+')
                {
                    st.push(op1 + op2);
                }
                else if (c == '-')
                {
                    st.push(op1 - op2);
                }
            }
        }

        cout << st.top() << endl;
    }

    return 0;
}
