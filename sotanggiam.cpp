#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool inc = true, dec = true;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] > s[i - 1])
                dec = false;
            else if (s[i] < s[i - 1])
                inc = false;
        }
        if (inc || dec)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
