#include <iostream>

using namespace std;
/*
// Hàm tính ước chung lớn nhất
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Hàm tính bội chung nhỏ nhất
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int UCLN = gcd(a, b);
        int BCNN = lcm(a, b);
        cout << UCLN << " " << BCNN;
    }
}
*/
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int gcd = a, n = b;
        while(n > 0) {
            int temp = gcd % n;
            gcd = n;
            n = temp;
        }
        long long lcm = (a*b)/gcd;
        cout << gcd << " " << lcm << endl;
        }
    }
