#include <bits/stdc++.h>
using namespace std;

int gt(int n) {
    if(n == 0){
        return 1;
    }
    else {
        return n * gt(n - 1);
    }
}

long long fibo(int n) {
    if(n <= 1)
        return n;
    else 
        return fibo(n-1)+fibo(n-2);
}

int nCk(int n, int k) {
    if(k == 0 || n == k)
        return 1;
    else return nCk(n-1, k) +nCk(n-1, k -1);
}

int gcd(int a, int b) {
    if(b == 0)
        return a;
    else return gcd(b, a%b);
}

int bipow(int a, int b) {
    if(b == 0) 
        return 1;
    int x = bipow(a, b/2);
    if(b % 2 == 1)
        return a*x*x;
    else return x*x;
}

int count(int n) {
    if(n < 10) 
        return 1;
    else 
        return 1 + count(n / 10);
}

int palin(int a[], int l, int r) {
    if(l >= r) 
        return 1;
    if(a[l] != a[r]) 
        return 0;
    else return palin(a, l+1, r-1);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    if(palin(a, 0, n-1))
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}