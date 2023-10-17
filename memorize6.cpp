#include <bits/stdc++.h>
using namespace std;

int maxD(string s) {
    int n = s.length();
    unordered_map<char, int> freq;
    int left = 0, right = 0;
    int maxD = 0;

    while(right < n) {
        freq[s[right]]++;
        while(freq.size() > 2) {
            fre[s[left]]--;
            if(freq[s[left]] == 0) 
                freq.erase(s[left]);
            left++;
        }
        if(freq.size() == 2) {
            auto it = freq.begin();
            int A = it->second;
            it++;
            int B = it->second;
            maxD = max(maxD, abs(A-b));
        }
        right++;
    }

    return maxD;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << maxDiff(s) << endl;
}