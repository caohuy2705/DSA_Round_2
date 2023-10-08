#include <iostream>
#include <string>
using namespace std;

 int main() {
    string s;
    getline(cin, s);
    int count = 0;
    for (int i=0; i <s.size()-1; i++) {
        int p = 0, arr[200] = {0};
        for(int j=i+1; j<s.size(); j++) {
            if(s[i] == s[j]) {
                p=j;
            }
        }
        if(p==0 || p == i+1) continue;
        for(int j = i+1; j < p; j++) {
            arr[s[j]]++;
        }
        for(int j = 'A'; j <= 'Z'; j++) {
            if(arr[j]==1) count++;
        }
    }
    cout << count/2 << endl;
 }