#include <bits/stdc++.h>
using namespace std;

int n, x[100];

void inkq(){
    for(int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
void Try(int i) {
    //duyet cac kha nang cua x[i]
    for(int j = 0; j <= 1; j++) { //2khar nang 0 1 
        x[i] = j;
        if(i == n) { //xay den bit cuoi cung n
            inkq();
        } else Try(i+1);
    }
}

int main() {
    cin >> n;
    Try(1);
    return 0;
}
