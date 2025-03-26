#include "Merge_sort.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
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
    if (n > 1) {
        int m = n / 2;
        mergeSort(lo, m);      // Sort first half
        mergeSort(lo + m, m);  // Sort second half
        merge(lo, n);          // Merge the two halves
    }
}

void MergeSorter::merge(int lo, int n) {
    if (n <= 1) return;

    int mid = n / 2;
    // Step 1: Compare elements between the two halves (n/2 with n, n/2 with n+1, etc.)
    for (int i = 0; i < mid; i++) {
        int a = lo + i;         // From first half
        for (int j = 0; j < mid; j++) {
            int b = lo + mid + j;  // From second half
            swapPairs.emplace_back(a, b);
        }
    }

    // Step 2: Compare adjacent elements in the second half (n with n+1, n+1 with n+2, etc.)
    for (int i = lo + mid; i + 1 < lo + n; i++) {
        swapPairs.emplace_back(i, i + 1);
    }

    // Step 3: Compare adjacent elements in the first half to ensure sorting
    for (int i = lo; i + 1 < lo + mid; i++) {
        swapPairs.emplace_back(i, i + 1);
    }

    // Recursively merge subparts if needed
    merge(lo, mid);
    merge(lo + mid, n - mid);
}

std::vector<std::pair<int, int>> MergeSorter::generateSwapPairs(int n) {
    swapPairs.clear();
    int newSize = nextPowerOf2(n);

    // Generate merge sort network
    mergeSort(0, newSize);

    // Filter swap pairs to only include indices < n
    std::vector<std::pair<int, int>> filtered;
    for (const auto& p : swapPairs) {
        if (p.first < n && p.second < n) {
            filtered.push_back(p);
        }
    }
    swapPairs = filtered;
    maxSwaps = swapPairs.size();
    return swapPairs;
}

void MergeSorter::sort(std::vector<int>& arr) {
    int n = arr.size();
    int newSize = nextPowerOf2(n);
    if (!isPowerOf2(n)) {
        arr.resize(newSize, INT_MAX);
    }

    // Apply the swap pairs
    for (const auto& [a, b] : swapPairs) {
        if (a < arr.size() && b < arr.size() && arr[a] > arr[b]) {
            std::swap(arr[a], arr[b]);
        }
    }

    // Trim back to original size if padded
    if (n != arr.size()) {
        arr.resize(n);
    }
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
