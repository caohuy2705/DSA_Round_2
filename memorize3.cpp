#include <bits/stdc++.h>
#include <unordered_map> 
using namespace std;

int maxDiff(string s) {
    int n = s.length();
    unordered_map<char, int> freq;
    int left = 0, right = 0;
    int maxD = 0;
    while(right < n) {
        freq[s[right]++];
        while(freq.size() > 2) {
            freq[s[left]]--;
            if(freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }
        if(freq.size() == 2) {
            auto it = freq.begin();
            int A = it->second;
            it++;
            int B = it->second;
            maxD=max(maxD, abs(A-B));
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
    int result = maxDiff(s);
    cout << result << endl;
}