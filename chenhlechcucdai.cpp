#include <iostream>
#include <unordered_map>
using namespace std;

int maxDifference(string s) {
    int n = s.length();
    unordered_map<char, int> freq;

    int left = 0, right = 0;
    int maxDiff = 0;

    while (right < n) {
        freq[s[right]]++;
        while (freq.size() > 2) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }
        if (freq.size() == 2) {
            auto it = freq.begin();
            int A = it->second;
            it++;
            int B = it->second;
            maxDiff = max(maxDiff, abs(A - B));
        }
        right++;
    }

    return maxDiff;
}

int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    int result = maxDifference(s);
    cout << result << endl;

    return 0;
}
