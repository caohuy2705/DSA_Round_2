#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n) {
    int ans = 0;
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                ans++;  
            }
        }
        if (!swapped)
            break;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int swaps = bubbleSort(arr, n);
        cout << swaps << endl;
    }

    return 0;
}
