#include <iostream>
#include <algorithm>

using namespace std;

void printPattern(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        cout << arr[right] << " " << arr[left] << " ";
        left++;
        right--;
    }

    if (n % 2 != 0) {
        cout << arr[left];
    }

    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int arr[1003];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        printPattern(arr, n);
    }

    return 0;
}