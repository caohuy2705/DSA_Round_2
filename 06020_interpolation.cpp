#include <bits/stdc++.h>
using namespace std;
/* old 
int interpolationSearch(int a[], int n, int x) {
    int low = 0; //cận dưới của dãy khoá 
    int high = n-1; //cận trên của dãy khoá
    if(x < a[low] || x > a[high]) {
        return (-1); //chắc chắn x không có mặt trong dãy 
    }
    while(low <= high) { //lặp lại khi cần dưới bé hơn cận trên 
        int pos = low + (((high - low) / (a[high] - a[low])) * (x - a[low])); //xác định vị trí theo công thức
        if(a[pos] == x) //nếu vị trí đúng là x 
            return 1; //trả về vị trí cần tìm
        if(a[pos] < x) //nếu x lớn hơn a[pos]
            low = pos + 1; //dịch cận dưới lên 1
        else //nếu x bé hơn a[pos]
            high = pos - 1; //giảm cận trên đi 1 
    }
        return (-1); //kết luận không tìm thấy x
} */
int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {  // Nếu chỉ còn một phần tử trong đoạn
            if (arr[low] == x)  // Nếu phần tử duy nhất là số cần tìm
                return 1;  // Trả về 1 (số cần tìm có mặt trong mảng)
            return -1;  // Trả về -1 (số cần tìm không có mặt trong mảng)
        }

        // Tính toán vị trí ước lượng của x dựa trên interpolation formula
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x)  // Nếu phần tử tại vị trí ước lượng là số cần tìm
            return 1;  // Trả về 1 (số cần tìm có mặt trong mảng)

        if (arr[pos] < x)
            low = pos + 1;  // X nằm ở phía bên phải vị trí ước lượng
        else
            high = pos - 1;  // X nằm ở phía bên trái vị trí ước lượng
    }

    return -1;  // Trả về -1 (số cần tìm không có mặt trong mảng)
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << interpolationSearch(arr, n, x) << endl;
}
    }
