#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], isFinal;

void ktao() {
    for(int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}

void sinh() {
    int i = n;
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if(i == 0) {
        isFinal = 0;
    }
    else a[i] = 1;
}

int bitcheck() {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += a[i];
    }
    return(sum == k);
}

void output() {
        for(int i = 1; i <= n; i++) {
            cout << a[i];
        }
        cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ktao();
        isFinal = 1;
        while(isFinal) {
            if(bitcheck()){
                output();
            }
            sinh();
        }
        cout << endl;
    }
}