#include "Merge_sort.hpp"
using namespace std;

MergeSorter::MergeSorter() : maxSwaps(0) {}

// Helper function for merging two sorted subarrays
void MergeSorter::merge(std::vector<int>& arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    
    vector<int> temp(right - left + 1);
    int k = 0;

    // Merge the two subarrays
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // Record swap pairs for elements that need to move
            for (int m = i; m <= mid; m++) {
                swapPairs.push_back({m, j-1});
            }
        }
    }

    // Copy remaining elements from left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

// Recursive merge sort implementation
void MergeSorter::mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Main sort function
void MergeSorter::sort(vector<int>& arr) {
    swapPairs.clear();
    if (arr.empty()) return;
    
    mergeSort(arr, 0, (int)arr.size() - 1);
    maxSwaps = (int)swapPairs.size();
}

// Calculate depth (longest path from input to output)
int MergeSorter::depth(vector<int>& arr) {
    if (arr.empty()) return 0;
    
    // For merge sort, depth is log2(n) where n is array size
    int n = (int)arr.size();
    return static_cast<int>(ceil(log2(n)));
}

// Get maximum number of swaps
int MergeSorter::getMaxSwaps() const {
    return maxSwaps;
}
