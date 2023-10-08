#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int currentElement = arr[i];
        int j = i - 1;

        // Di chuyển các phần tử lớn hơn currentElement một vị trí sang phải
        // Đồng thời, kiểm tra xem currentElement có nhỏ hơn phần tử đang xét không
        while (j >= 0 && arr[j] > currentElement) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Chèn currentElement vào vị trí thích hợp trong dãy con đã sắp xếp
        arr[j + 1] = currentElement;

        // In ra màn hình từng bước thực hiện thuật toán
        cout << "Buoc " << i << ": ";
        for (int k = 0; k <= i; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Buoc 0: " << arr[0] << endl;

    insertionSort(arr, n);

    return 0;
}
