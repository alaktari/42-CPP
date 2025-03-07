#include <iostream>
#include <vector>

// Insertion Sort for small subarrays
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge function
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<int> leftArr(leftSize), rightArr(rightSize);

    for (int i = 0; i < leftSize; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }

    while (i < leftSize) arr[k++] = leftArr[i++];
    while (j < rightSize) arr[k++] = rightArr[j++];
}

// Merge-Insertion Sort function
void mergeInsertionSort(std::vector<int>& arr, int left, int right, int threshold)
{
    if (right - left + 1 <= threshold) {
        insertionSort(arr, left, right);
        return;
    }

    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeInsertionSort(arr, left, mid, threshold);
        mergeInsertionSort(arr, mid + 1, right, threshold);

        std::cout << "\n\nin progress: ";
        for (int num : arr) std::cout << num << " ";
        exit(0);

        merge(arr, left, mid, right);
    }
}

// Wrapper function
void sort(std::vector<int>& arr, int threshold = 10) {
    mergeInsertionSort(arr, 0, arr.size() - 1, threshold);
}

// Main function
int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7, 18, 20, 1, 88, 0, -1};
    
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    
    sort(arr); // Using Merge-Insertion Sort
    
    std::cout << "\nSorted array: ";
    for (int num : arr) std::cout << num << " ";

    return 0;
}
