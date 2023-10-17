#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> M(m);
    iota(M.begin(), M.end(), 1);
    do {
        if(M[m-1] == n) {
            for(auto c:M) 
                cout << c << " ";
                cout << endl;
        }
    } while(next_permutation(M.begin(), M.end()));
}