//
//  OddEvenSorter.cpp
//  proj_1
//
//  Created by Rabeea on 26/03/2025.
//

#include "OddEvenSorter.hpp"
OddEvenSorter::OddEvenSorter() : swaps(0) {}

void OddEvenSorter::sort(std::vector<int>& arr) {
    swaps = 0;
    for (const auto& [a, b] : swapPairs) {
        if (a < arr.size() && b < arr.size() && arr[a] > arr[b]) {
            std::swap(arr[a], arr[b]);
            swaps++;
        }
    }
}

std::vector<std::pair<int, int>> OddEvenSorter::generateSwapPairs(int n) {
    swapPairs.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - 1; j += 2) {
            swapPairs.emplace_back(j, j + 1);
        }
        for (int j = 0; j < n - 1; j += 2) {
            swapPairs.emplace_back(j, j + 1);
        }
    }
    return swapPairs;
}

int OddEvenSorter::getMaxSwaps() const {
    return swapPairs.size();
}

int OddEvenSorter::depth(const std::vector<int>& arr) const {
    return arr.size();
}
