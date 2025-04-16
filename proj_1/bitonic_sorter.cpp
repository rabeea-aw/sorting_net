#include "bitonic_sorter.hpp"
#include <algorithm>
#include <cmath>

BitonicSorter::BitonicSorter() : maxSwaps(0) {
    swapPairs.clear();
}

bool BitonicSorter::isPowerOf2(int n) const {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int BitonicSorter::nextPowerOf2(int n) const {
    return pow(2, ceil(log2(n)));
}

int greatestPowerOfTwoLessThan(int n) {
    int k = 1;
    while (k > 0 && k < n) {
        k <<= 1;
    }
    return k >> 1;
}

void BitonicSorter::generateBitonicPairs(int low, int cnt, bool dir) {
    if (cnt <= 1) return;

    // Bitonic merge step
    int m = greatestPowerOfTwoLessThan(cnt);
    for (int i = low; i < low + cnt - m; i++) {
        // Ensure ascending/descending order in swap pairs
        if (dir) {
            swapPairs.emplace_back(i, i + m); // Ascending: smaller index first
        } else {
            swapPairs.emplace_back(i + m, i); // Descending: larger index first
        }
    }

    // Recursively merge the two parts
    generateBitonicPairs(low, m, dir);
    generateBitonicPairs(low + m, cnt - m, dir);
}

std::vector<std::pair<int, int>> BitonicSorter::generateSwapPairs(int n) {
    swapPairs.clear();
    if (n < 2) {
        maxSwaps = 0;
        return swapPairs;
    }

    // Recursive bitonic sort
    auto bitonicSort = [&](int low, int cnt, bool dir, auto& self) -> void {
        if (cnt <= 1) return;

        int m = cnt / 2;
        self(low, m, !dir, self);           // Sort first half in opposite direction
        self(low + m, cnt - m, dir, self);  // Sort second half in desired direction
        generateBitonicPairs(low, cnt, dir); // Merge the two halves
    };

    bitonicSort(0, n, true, bitonicSort); // Sort in ascending order
    maxSwaps = swapPairs.size();
    return swapPairs;
}

void BitonicSorter::sort(std::vector<int>& arr) {
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

int BitonicSorter::getMaxSwaps() const {
    return maxSwaps;
}

int BitonicSorter::depth(const std::vector<int>& arr) const {
    int n = arr.size();
    if (n < 2) return 0;

    // Calculate depth based on recursive structure
    auto calculateDepth = [&](int cnt, auto& self) -> int {
        if (cnt <= 1) return 0;
        int m = cnt / 2;
        int mergeDepth = 0;
        for (int k = greatestPowerOfTwoLessThan(cnt); k >= 1; k >>= 1) {
            mergeDepth++;
        }
        return std::max(self(m, self), self(cnt - m, self)) + mergeDepth;
    };
    return calculateDepth(n, calculateDepth);
}
