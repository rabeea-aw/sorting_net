#include "Merge_sort.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

MergeSorter::MergeSorter() : maxSwaps(0) {
    swapPairs.clear();
}

bool MergeSorter::isPowerOf2(int n) const {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int MergeSorter::nextPowerOf2(int n) const {
    return pow(2, ceil(log2(n)));
}

void MergeSorter::generateMergePairs(int low, int cnt) {
    if (cnt <= 1) return;

    // Split the array into two halves
    int m = cnt / 2;
    
    // Recursively generate pairs for each half
    generateMergePairs(low, m);
    generateMergePairs(low + m, cnt - m);
    
    // Merge the two sorted halves
    merge(low, m, low + m, cnt - m);
}

void MergeSorter::merge(int lo1, int n1, int lo2, int n2) {
    int total = n1 + n2;
    int m = nextPowerOf2(total);
    
    // Odd-even merge algorithm
    for (int k = m / 2; k > 0; k /= 2) {
        for (int j = k % (m / 2); j + k < total; j += 2 * k) {
            for (int i = 0; i < k; i++) {
                int a = lo1 + j + i;
                int b = lo1 + j + i + k;
                
                // Ensure we don't go out of bounds
                if (b < lo1 + total) {
                    swapPairs.emplace_back(a, b);
                }
            }
        }
    }
}

std::vector<std::pair<int, int>> MergeSorter::generateSwapPairs(int n) {
    swapPairs.clear();
    if (n < 2) {
        maxSwaps = 0;
        return swapPairs;
    }

    // Pad to next power of 2 if needed
    int padded_n = isPowerOf2(n) ? n : nextPowerOf2(n);
    
    // Generate the merge sort network
    generateMergePairs(0, padded_n);
    
    // Filter out pairs that are beyond the original array size
    std::vector<std::pair<int, int>> validPairs;
    for (const auto& pair : swapPairs) {
        if (pair.first < n && pair.second < n) {
            validPairs.push_back(pair);
        }
    }
    
    swapPairs = validPairs;
    maxSwaps = swapPairs.size();
    for (const auto& pair : swapPairs) {
        std::cout <<pair.first<< ","<<pair.second <<"\n";
    }
    
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
    if (n < 2) return 0;

    // Calculate depth based on merge sort network structure
    auto calculateDepth = [&](int cnt, auto& self) -> int {
        if (cnt <= 1) return 0;
        int m = cnt / 2;
        int mergeDepth = 0;
        for (int k = nextPowerOf2(cnt); k > 0; k /= 2) {
            mergeDepth++;
        }
        return std::max(self(m, self), self(cnt - m, self)) + mergeDepth;
    };
    
    return calculateDepth(n, calculateDepth);
}
