#include "bitonic_sorter.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

BitonicSorter::BitonicSorter() : maxSwaps(0) {
    swapPairs.clear();
}

bool BitonicSorter::isPowerOf2(int n) const {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int BitonicSorter::nextPowerOf2(int n) const {
    return pow(2, ceil(log2(n)));
}

void BitonicSorter::generateBitonicPairs(int low, int cnt, bool dir) {
    if (cnt <= 1) return;

    int k = cnt / 2;
    // First, generate pairs for the bitonic merge
    for (int i = 0; i < k; i++) {
        int a = low + i;
        int b = low + i + k;
        if (dir) {
            swapPairs.emplace_back(a, b); // Ascending: compare a with b
        } else {
            swapPairs.emplace_back(b, a); // Descending: compare b with a
        }
    }

    // Recursively generate pairs for the two halves
    generateBitonicPairs(low, k, dir);      // First half
    generateBitonicPairs(low + k, k, dir);  // Second half
}

std::vector<std::pair<int, int>> BitonicSorter::generateSwapPairs(int n) {
    swapPairs.clear();
    int newSize = nextPowerOf2(n);

    // Generate bitonic sort network
    for (int size = 2; size <= newSize; size *= 2) {
        for (int i = 0; i < newSize; i += size) {
            bool dir = (i / size) % 2 == 0; // Ascending for even groups, descending for odd
            generateBitonicPairs(i, size, dir);
        }
    }

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

void BitonicSorter::sort(std::vector<int>& arr) {
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

int BitonicSorter::getMaxSwaps() const {
    return maxSwaps;
}

int BitonicSorter::depth(const std::vector<int>& arr) const {
    int n = arr.size();
    int paddedSize = nextPowerOf2(n);
    int stages = log2(paddedSize);
    return stages * (stages + 1) / 2;
}
