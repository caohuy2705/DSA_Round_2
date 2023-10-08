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
        int pos = s.find_last_of(' ');
        string last_name = s.substr(pos + 1);
        string first_name = s.substr(0, pos);
        cout << last_name << ", " << first_name << endl;
    }
    return 0;
}