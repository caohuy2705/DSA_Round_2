#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 2];
        a[0] = a[1] = 0;
        for (int i = 2; i <= n + 1; i++)
        {
            cin >> a[i];
            a[i] = max(a[i] + a[i - 2], a[i - 1]);
        }
        cout << max(a[n], a[n + 1]) << endl;
    }
}
