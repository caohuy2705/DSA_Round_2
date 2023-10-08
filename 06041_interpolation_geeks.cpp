#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target)
                return left;
            return -1;
        }

        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1;
}

int findFrequency(const vector<int>& arr) {
    int n = arr.size();
    int candidate = arr[0];
    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == candidate)
            count++;
        else {
            count--;
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            }
        }
    }

    count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == candidate)
            count++;
    }

    if (count > n / 2)
        return candidate;

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; ++i)
            cin >> arr[i];

        int candidate = findFrequency(arr);

        if (candidate != -1) {
            int frequency = 0;
            for (int num : arr) {
                if (num == candidate)
                    frequency++;
            }

            if (frequency > N / 2)
                cout << candidate << endl;
            else
                cout << "NO" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
