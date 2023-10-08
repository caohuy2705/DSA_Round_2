#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(string& s) {
    int n = s.length();
    for(int i = 0; i < n-1; i++) {
        int min_index = i;
        for(int j = i+1; j < n; j++) {
            if(s[j] < s[min_index]) {
                min_index = j;
            }
        }
        swap(s[i], s[min_index]);
    }
}

void solve() {
    int n;
    cin >> n;
    string s=" ", temp = " ";
    for(int i = 0; i < n;i++) {
        cin >> temp;
        s+=temp;
    }
    selectionSort(s);
        for(int i =  0; i < s.length(); i++) {
            if(s[i] != s[i+1])
                cout << s[i] << ' ';
        }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
        return 0;
    }
}
