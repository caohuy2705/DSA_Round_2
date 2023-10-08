#include <bits/stdc++.h>
using namespace std;

int n, a[100], isFinal;

void ktao() { //Thiết lập cấu hình đầu tiên 
	for(int i = 1; i <= n; i++) {
		a[i] = 0;
	}
}

void output() {//in ra A nếu a[i] = 0, in ra B nếu a[i] = 1
	for(int i = 1; i <= n; i++) {
		if(a[i] == 0) {
			cout << 'A';
		}
		else cout << 'B';
	}
	cout << " ";
}

void sinh() { //sinh cấu hình kế tiếp 
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

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
        isFinal = 1;
		while(isFinal) {//while(<Lặp khi cấu hình chưa phải cuối cùng>)
            output(); //<Đưa ra cấu hình hiện tại>
            sinh(); //<Sinh ra cấu hình kế tiếp>
        }
        cout << endl;
	}
}
