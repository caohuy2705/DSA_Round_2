#include <bits/stdc++.h>
using namespace std;

int ternarySearch(int l, int r, int a[], int n, int x) {
        if(r >= l) {
        int mid1 = l+(r-l)/3;
        int mid2 = r-(r-l)/3;
        //tìm xem có x có bằng mid không 
        if(a[mid1] == x) 
            return 1; //trả về 1 nếu n = mid 
        if(a[mid2] == x) 
            return 1;
        
        //không có x = mid -> tìm xem x nằm trong vùng nào và thực hiện search 
        if(x < a[mid1]) {
            return ternarySearch(l, mid1-1, a, n, x); //x nằm giữa l mà mid 1
        }
        else if (x > a[mid2]) {
            return ternarySearch(mid2+1, r, a, n, x); //x nằm giữa mid2 và r
        }
        else {
            return ternarySearch(mid1+1, mid2-1, a, n, x); //x nằm giữa mid1 và mid2
        }
    }
    return (-1);
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
        int l = 0; //cận trên 
        int r = n-1; //cận dưới  
        cout << ternarySearch(l, r, a, n, x) << endl;
    }
}

/*
int ternarySearch(int l, int r, int key, int ar[])
{
    if (r >= l) {
 
        // Find the mid1 and mid2
        int mid1 = l + (r - ) / 3;
        int mid2 = r - (r - l) / 3;
 
        // Check if key is present at any mid
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }
 
        // Since key is not present at mid,
        // check in which region it is present
        // then repeat the Search operation
        // in that region
        if (key < ar[mid1]) {
 
            // The key lies in between l and mid1
            return ternarySearch(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]) {
 
            // The key lies in between mid2 and r
            return ternarySearch(mid2 + 1, r, key, ar);
        }
        else {
 
            // The key lies in between mid1 and mid2
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        }
    }
 
    // Key not found
    return -1;
}
*/