#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

// Hàm sắp xếp bằng Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

// Hàm sắp xếp bằng Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm sắp xếp bằng Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Hàm sắp xếp bằng Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm sắp xếp bằng Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Hàm khởi tạo dãy số ngẫu nhiên
vector<int> generateRandomArray(int n) {
    vector<int> arr(n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand();
    return arr;
}

// Hàm in ra dãy số
void printArray(const vector<int>& arr) {
    int n = arr.size();
    if (n > 100) {
        cout << "Array is too large to print." << endl;
        return;
    }
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr_sizes = {10, 100, 1000, 10000, 50000, 100000}; // Các giá trị n khác nhau

    for (int n : arr_sizes) {
        vector<int> arr = generateRandomArray(n);

        // Selection Sort
        auto start_time = chrono::high_resolution_clock::now();
        selectionSort(arr);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_time = end_time - start_time;
        cout << "Selection Sort with n = " << n << " took: " << elapsed_time.count() << " seconds" << endl;

        // Insertion Sort
        arr = generateRandomArray(n);
        start_time = chrono::high_resolution_clock::now();
        insertionSort(arr);
        end_time = chrono::high_resolution_clock::now();
        elapsed_time = end_time - start_time;
        cout << "Insertion Sort with n = " << n << " took: " << elapsed_time.count() << " seconds" << endl;

        // Bubble Sort
        arr = generateRandomArray(n);
        start_time = chrono::high_resolution_clock::now();
        bubbleSort(arr);
        end_time = chrono::high_resolution_clock::now();
        elapsed_time = end_time - start_time;
        cout << "Bubble Sort with n = " << n << " took: " << elapsed_time.count() << " seconds" << endl;

        // Quick Sort
        arr = generateRandomArray(n);
        start_time = chrono::high_resolution_clock::now();
        quickSort(arr, 0, n - 1);
        end_time = chrono::high_resolution_clock::now();
        elapsed_time = end_time - start_time;
        cout << "Quick Sort with n = " << n << " took: " << elapsed_time.count() << " seconds" << endl;

        // Merge Sort
        arr = generateRandomArray(n);
        start_time = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        end_time = chrono::high_resolution_clock::now();
        elapsed_time = end_time - start_time;
        cout << "Merge Sort with n = " << n << " took: " << elapsed_time.count() << " seconds" << endl;

        cout << endl;
    }

    return 0;
}