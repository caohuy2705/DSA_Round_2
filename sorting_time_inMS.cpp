#include <iostream>
#include <ctime>
using namespace std;

// Hàm in ra mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm hoán đổi giá trị của hai số nguyên
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
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

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Hàm tạo mảng ngẫu nhiên
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 10); // Tạo giá trị ngẫu nhiên từ 0 đến n * 10 - 1
    }
}

int main() {
    int lengths[] = {10, 100, 1000, 10000, 50000, 100000};
    int num_lengths = sizeof(lengths) / sizeof(lengths[0]);

    for (int i = 0; i < num_lengths; i++) {
        int n = lengths[i];
        int *arr = new int[n];

        // Tạo mảng ngẫu nhiên
        generateRandomArray(arr, n);

        // Selection Sort
        clock_t startTime = clock();
        selectionSort(arr, n);
        clock_t endTime = clock();
        cout << "Selection Sort (n = " << n << "): ";
        cout << "Thoi gian thuc thi: " << double(endTime - startTime) / CLOCKS_PER_SEC << " giay" << endl;

        // Reset lại mảng gốc
        generateRandomArray(arr, n);

        // Insertion Sort
        startTime = clock();
        insertionSort(arr, n);
        endTime = clock();
        cout << "Insertion Sort (n = " << n << "): ";
        cout << "Thoi gian thuc thi: " << double(endTime - startTime) / CLOCKS_PER_SEC << " giay" << endl;

        // Reset lại mảng gốc
        generateRandomArray(arr, n);

        // Bubble Sort
        startTime = clock();
        bubbleSort(arr, n);
        endTime = clock();
        cout << "Bubble Sort (n = " << n << "): ";
        cout << "Thoi gian thuc thi: " << double(endTime - startTime) / CLOCKS_PER_SEC << " giay" << endl;

        // Reset lại mảng gốc
        generateRandomArray(arr, n);

        // Quick Sort
        startTime = clock();
        quickSort(arr, 0, n - 1);
        endTime = clock();
        cout << "Quick Sort (n = " << n << "): ";
        cout << "Thoi gian thuc thi: " << double(endTime - startTime) / CLOCKS_PER_SEC << " giay" << endl;

        // Reset lại mảng gốc
        generateRandomArray(arr, n);

        // Merge Sort
        startTime = clock();
        mergeSort(arr, 0, n - 1);
        endTime = clock();
        cout << "Merge Sort (n = " << n << "): ";
        cout << "Thoi gian thuc thi: " << double(endTime - startTime) / CLOCKS_PER_SEC << " giay" << endl;

        delete[] arr;
    }

    return 0;
}
