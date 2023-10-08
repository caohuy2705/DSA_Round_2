#include <iostream>
using namespace std;

bool isSymmetric(int arr[], int n) {
    int start = 0;         
    int end = n - 1;        

    while (start <= end) {
        if (arr[start] != arr[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (isSymmetric(arr, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

