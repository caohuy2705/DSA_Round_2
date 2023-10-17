#include <bits/stdc++.h>
using namespace std;

int n, a[100], used[100];

void inkq() {
    for(int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
}

void Try(int i) { //Thuật toán Back-Track ( int i ) {
    //duyet cac kha nang ma a[i] co the nhan duoc
    for(int j = 1; j <= n; j++) { //for ( j =<Khả năng 1>; j <=ni; j++ ){
        // xet xem co the gan a[i] = j hay khong 
        if(used[j] == 0) { //if (<chấp thuận khả năng j>) {
            a[i] = j; //X[i] = <khả năng j>;
            used[j] = 1; //danh dau da su dung 
            if(i == n) { //if ( i ==n) Result();
                inkq();
            }
            else { //else Back-Track(i+1);
                Try(i+1);
            }
            //backtrack
            used[j] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        memset(used, 0, sizeof(used));
        Try(1);
        return 0;
    }
}