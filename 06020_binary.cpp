#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int n, int x) {
    int low = 0; //cận dưới của dãy khoá 
    int high = n-1; //cận trên của dãy khoá
    int mid = (low+high)/2; //phần tử ở giữa
    while(low <= high) { //lặp lại khi cận dưới vẫn nhỏ hơn cận trên
        if(x > a[mid]) { //nếu x lớn hơn phần tử ở giữa 
            low = mid+1; //cận dưới được đặt lên vị trí mid+1
        } else if (x < a[mid]) {
            high = mid-1; //cận trên lùi về vị trí mid-1
        } else 
           // return (mid); //đây là vị trí của x 
           return (1); //tim thay x 
        mid = (low + high)/2; //xác định lại phần tử ở giữa
    }
    return (-1); // không tìm thấy x
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << binarySearch(a, n, x) << endl;
    }
}