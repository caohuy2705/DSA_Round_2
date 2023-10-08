#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], isFinal;

void ktao() {
    for(int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void sinh() {
    int i = k;
    //max: n-k+i
    while(i >= 1 && a[i] == n-k+i) { //i >= i: khong xet doan ngoai` i=1,
        --i; //dich i sang trai 
    }
    if(i == 0) {
        isFinal = 0; //day la cau hinh cuoi cung
    }
    else {
        a[i]++;
        for(int j = i+1; j <= k; j++) {
            a[j] = a[j-1]+1; //a[j] dung sau = a[j-1] dung truoc +1
        }
    }
}

void output() {
        for(int i = 1; i <= k; i++) {
            cout << a[i];
        }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        isFinal = 1;
        ktao();
        while(isFinal) {
            output();
            sinh();
            cout << " ";
        }
        cout << endl;
    }
}