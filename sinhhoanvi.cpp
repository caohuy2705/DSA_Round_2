#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], isFinal;

void ktao() {
    for(int i = 1; i<= n; i++) {
        a[i] = i;
    }
}
//next_permutation_hoanvinguoc
void sinh() {
    int i = n-1;
    while(i >= 1 && a[i] > a[i+1]) {
        --i;
    }
    if(i == 0) {
        isFinal = 0; //cau hinh cuoi cung
    }
    else {
        //di tim a[i] trong doan [i+1, n]
        int j = n;
        while(a[i] > a[j]) {
            --j;
        }
        swap(a[i], a[j]);
        int l = i+1, r=n;
        while(l < r) {
            swap(a[l], a[r]);
            ++l;
            --r;
        }
        //reverse(a+i+1, a+n+1);
    }
}
void output() {
    for(int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << " ";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        isFinal = 1;
        ktao();
        while(isFinal) {
            output();
            sinh();
        }
    cout << endl;
    }

}