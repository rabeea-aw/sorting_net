#include "Merge_sort.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <climits>

MergeSorter::MergeSorter() : maxSwaps(0) {
    swapPairs.clear();
}

bool MergeSorter::isPowerOf2(int n) const {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int MergeSorter::nextPowerOf2(int n) const {
    return pow(2, ceil(log2(n)));
}

void MergeSorter::mergeSort(int lo, int n) {
    if (n <= 1) return;
    
    int mid = n / 2;
    mergeSort(lo, mid);
    mergeSort(lo + mid, n - mid);
    merge(lo, n);
}

void MergeSorter::merge(int lo, int n) {
    if (n <= 1) return;
    
    int mid = n / 2;
    int p = lo;
    int q = lo + mid - 1;
    int r = lo + n - 1;
    
    // Create left and right subarrays (L and M)
    int n1 = q - p + 1;
    int n2 = r - q;
    
    std::vector<int> L(n1);
    std::vector<int> M(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    
    // Merge L and M back into arr
    int i = 0, j = 0, k = p;
    
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            // Generate swap pairs for elements in L that are larger
            for (int m = i; m < n1; m++) {
                int left_idx = p + m;
                int right_idx = q + 1 + j;
                if (left_idx < arr.size() && right_idx < arr.size()) {
                    swapPairs.emplace_back(left_idx, right_idx);
                    maxSwaps++;
                }
            }
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
        arr[k] = M[j];
        j++;
        k++;
    }
}

void MergeSorter::sort(std::vector<int>& arr) {
    this->arr = arr;
    maxSwaps = 0;
    swapPairs.clear();
    
    int n = arr.size();
    int newSize = nextPowerOf2(n);
    if (!isPowerOf2(n)) {
        this->arr.resize(newSize, INT_MAX);
    }
    
    mergeSort(0, newSize);
    
    arr = this->arr;
    if (n != arr.size()) {
        arr.resize(n);
    }
}

std::vector<std::pair<int, int>> MergeSorter::generateSwapPairs(int n) {
    std::vector<int> arr(n);

    this->arr = arr;
    maxSwaps = 0;
    swapPairs.clear();
    
    int newSize = nextPowerOf2(n);
    if (!isPowerOf2(n)) {
        this->arr.resize(newSize, INT_MAX);
    }
    
    for (int i = 0; i < newSize; ++i) {
           if (i < newSize/2 ) {
               // First half: pair with middle element (4)
               swapPairs.emplace_back(i, newSize/2);
           } else {
               // Second half: pair with next element
               swapPairs.emplace_back(i, i + 1);
           }
       }
       
    
    // Filter swap pairs to only include indices < n and first < second
    std::vector<std::pair<int, int>> filtered;
    for (const auto& p : swapPairs) {
        if (p.first < n && p.second < n && p.first < p.second) {
            filtered.push_back(p);
        }
    }
    swapPairs = filtered;
    maxSwaps = swapPairs.size();
    
    // Print filtered swap pairs
    std::cout << "Swap Pairs after filtering:\n";
    for (const auto& p : filtered) {
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    }
    
    return swapPairs;
}

int MergeSorter::getMaxSwaps() const {
    return maxSwaps;
}

int MergeSorter::depth(const std::vector<int>& arr) const {
    int n = arr.size();
    int paddedSize = nextPowerOf2(n);
    int stages = log2(paddedSize);
    return stages * (stages + 1); // Approximate depth of merge sort network
}
