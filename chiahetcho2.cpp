#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, t, i, s;
    cin >> t;
    while(t--) {
        cin >> n;
        s=0;
        for(i=1; i<=(sqrt(n));i++) {
            if(n%i==0&&i%2==0) 
                s++;
            if(n%i==0 && i!=n/i && (n/i)%2==0)
                s++;
        }
        cout<<s<<endl;
    }
}