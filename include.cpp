//bubble
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//selection
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

//insertion
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//merge 
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

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

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

//quick 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//heap 
void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

//linear
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

//binary
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Return the index where the target is found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if the target is not found
}

//interpolation 
int interpolationSearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target) {
                return left; // Return the index where the target is found
            }
            return -1; // Return -1 if the target is not found
        }

        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));

        if (arr[pos] == target) {
            return pos; // Return the index where the target is found
        }

        if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1; // Return -1 if the target is not found
}

//jump
int jumpSearch(int arr[], int size, int target) {
    int jump = sqrt(size);
    int prev = 0;

    while (arr[min(jump, size) - 1] < target) {
        prev = jump;
        jump += sqrt(size);
        if (prev >= size) {
            return -1; // Return -1 if the target is not found
        }
    }

    while (arr[prev] < target) {
        prev++;

        if (prev == min(jump, size)) {
            return -1; // Return -1 if the target is not found
        }
    }

    if (arr[prev] == target) {
        return prev; // Return the index where the target is found
    }

    return -1; // Return -1 if the target is not found
}

//ternary 
int ternarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) {
            return mid1; // Return the index where the target is found
        }
        if (arr[mid2] == target) {
            return mid2; // Return the index where the target is found
        }

        if (target < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, target);
        } else if (target > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, target);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
        }
    }

    return -1; // Return -1 if the target is not found
}

//sinh nhi phan 
#include <iostream>
#include <vector>

void nextBinaryGeneration(std::vector<int>& binaryNum) {
    int n = binaryNum.size();
    int carry = 1;

    for (int i = n - 1; i >= 0 && carry; --i) {
        binaryNum[i] = (binaryNum[i] + carry) % 2;
        carry = binaryNum[i] == 0 ? 1 : 0;
    }
}

int main() {
    int n = 5; // Number of bits
    std::vector<int> binaryNum(n, 0);

    // Generate and print the first binary generation
    for (int num : binaryNum)
        std::cout << num;
    std::cout << std::endl;

    // Generate and print the next binary generations
    for (int i = 1; i < 10; ++i) {
        nextBinaryGeneration(binaryNum);
        for (int num : binaryNum)
            std::cout << num;
        std::cout << std::endl;
    }

    return 0;
}

//sinh hoan vi 
#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    if (i >= 0) {
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            --j;
        }
        std::swap(nums[i], nums[j]);
    }

    std::reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3};

    // Generate and print the first permutation
    for (int num : nums)
        std::cout << num << " ";
    std::cout << std::endl;

    // Generate and print the next permutations
    for (int i = 1; i < 6; ++i) {
        nextPermutation(nums);
        for (int num : nums)
            std::cout << num << " ";
        std::cout << std::endl;
    }

    return 0;
}

//sinh to hop 
#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    if (i >= 0) {
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            --j;
        }
        std::swap(nums[i], nums[j]);
    }

    std::reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3};

    // Generate and print the first permutation
    for (int num : nums)
        std::cout << num << " ";
    std::cout << std::endl;

    // Generate and print the next permutations
    for (int i = 1; i < 6; ++i) {
        nextPermutation(nums);
        for (int num : nums)
            std::cout << num << " ";
        std::cout << std::endl;
    }

    return 0;
}
