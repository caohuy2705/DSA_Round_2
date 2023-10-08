#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        bool cap = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (cap && isalpha(s[i]))
            {
                s[i] = toupper(s[i]);
                cap = false;
            }
            else if (s[i] == ' ')
                cap = true;
        }
        cout << s << endl;
    }
    return 0;
}