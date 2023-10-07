#include <bits/stdc++.h>
using namespace std;

int n, a[100], cot[100], d1[100], d2[100], cnt;
char m[100][100];
/* 
void inkq() {
    memset(m, 0, sizeof(m));
    for (int i = 1; i <= n; i++) {
        m[i][a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
*/
void Try(int i) { //thuat toan Backtrack
    // duyet cac kha nang 
    for (int j = 1; j <= n; j++) { //for ( j =<Khả năng 1>; j <=ni; j++ ){
        // chuan bi gan x[i] = j    
        if (cot[j] == 1 && d1[i - j + n] == 1 && d2[i + j - 1] == 1) { //if (<chấp thuận khả năng j>) {
            a[i] = j; //X[i] = <khả năng j>;
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;
            if (i == n) { //if ( i == n) Result();
                //inkq();
                cnt++;
            } else { //else Back-Track(i+1);
                Try(i + 1);
            }
            // backtrack
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cnt = 0;
        for (int i = 1; i <= 99; i++) {
            cot[i] = d1[i] = d2[i] = 1;
        }
        Try(1);
        cout << cnt << endl;
    }
    
}
