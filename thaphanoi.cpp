#include <bits/stdc++.h>
using namespace std;
int n;
void in(char a, char c) {
	cout << a << " -> " << c << endl;
}
void Try(int i, int a, int b, int c) {
	if (i==1)  // neu thoa man dieu kien dung
		in(a,c); // giai quyet truong hop suy bien
	else {  // neu khong thoa man dieu kien dung
		Try(i-1, a, c, b); // goi ham de quy
		in(a,c); // hau xu li ham de quy
		Try(i-1, b, a, c); // tiep tuc goi de quy
	}
}
main() {
	cin >> n;
	char a='A', b='B', c='C';
	Try (n, a, b, c);
}


