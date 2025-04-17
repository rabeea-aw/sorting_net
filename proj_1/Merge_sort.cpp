#include "Merge_sort.hpp"
#include <algorithm>
#include <cmath>

MergeSorter::MergeSorter() : maxSwaps(0) {
    swapPairs.clear();
}

bool MergeSorter::isPowerOf2(int n) const {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int MergeSorter::nextPowerOf2(int n) const {
    return pow(2, ceil(log2(n)));
}

void MergeSorter::oddEvenMerge(int lo, int n, int r) {
    int m = r * 2;
    if (m < n) {
        oddEvenMerge(lo, n, m);      // Even subsequence
        oddEvenMerge(lo + r, n, m);  // Odd subsequence
        for (int i = lo + r; i + r < lo + n; i += m) {
            swapPairs.emplace_back(i, i + r);
        }
    }
    else {
        swapPairs.emplace_back(lo, lo + r);
    }
}

void MergeSorter::oddEvenMergeSort(int lo, int n) {
    if (n > 1) {
        int m = n / 2;
        oddEvenMergeSort(lo, m);
        oddEvenMergeSort(lo + m, m);
        oddEvenMerge(lo, n, 1);
    }
}

std::vector<std::pair<int, int>> MergeSorter::generateSwapPairs(int n) {
    swapPairs.clear();
    if (n < 2) {
        maxSwaps = 0;
        return swapPairs;
    }

    // Ensure n is a power of 2 for odd-even mergesort
    int padded_n = nextPowerOf2(n);
    
    // Generate the sorting network
    oddEvenMergeSort(0, padded_n);
    
    // Filter out pairs that are out of bounds for the actual array size
    std::vector<std::pair<int, int>> filteredPairs;
    for (const auto& pair : swapPairs) {
        if (pair.first < n && pair.second < n) {
            filteredPairs.push_back(pair);
        }
    }
    
    swapPairs = filteredPairs;
    maxSwaps = swapPairs.size();
    return swapPairs;
}

void MergeSorter::sort(std::vector<int>& arr) {
    if (arr.size() < 2) return;

    // Generate swap pairs if not already done
    if (swapPairs.empty()) {
        generateSwapPairs(arr.size());
    }

    // Apply the swap pairs
    for (const auto& [a, b] : swapPairs) {
        if (a < arr.size() && b < arr.size() && arr[a] > arr[b]) {
            std::swap(arr[a], arr[b]);
        }
    }
}

int MergeSorter::getMaxSwaps() const {
    return maxSwaps;
}

int MergeSorter::depth(const std::vector<int>& arr) const {
    int n = arr.size();
    if (n <= 1) return 0;
    
    // Depth calculation for odd-even mergesort network
    int d = 0;
    for (int p = 1; p < n; p <<= 1) {
        for (int k = p; k >= 1; k >>= 1) {
            d++;
        }
    }
    return d;
}
