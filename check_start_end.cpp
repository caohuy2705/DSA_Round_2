#include <iostream>
#include <string>
using namespace std;

string check(int num) {
    string num_str = to_string(num);
    if (num_str[0] == num_str[num_str.length() - 1]) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int num;
        cin >> num;
        string result = check(num);
        cout << result << endl;
    }
    return 0;
}