#include <bits/stdc++.h>
using namespace std;
/* 
void sinh(int n, string s) {
    if(s.length() == n) {
        cout << s << " ";
        return;
    }
    sinh(n, s + "0");
    sinh(n, s + "1");
} */ 

int n, k, a[100], isFinal;

void ktao() {
    for(int i = 1; i <= n; i++) 
        a[i] = 0;
}

void sinh() {
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) {
        isFinal = 0;
    }
    else a[i] = 1;
}
/* 
int checkRev(int a[], int n) {
    int l = 1, r = n;
    while(l < r) {
        if(a[l] != a[r])
            return 0;
        l++;
        r--;
    }
    return 1;
} */ 

int bitCheck() {
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
        isFinal = 1;
        ktao();
        while(isFinal) {
            if(bitCheck()) {
                output();
            }
            sinh();
    } cout << endl;
    }
    
    
    
}