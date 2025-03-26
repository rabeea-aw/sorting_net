//
//  BubbleSort.cpp
//  project
//
//  Created by Rabeea on 13/03/2025.
//

#include "BubbleSort.hpp"

BubbleSorter::BubbleSorter() : swaps(0) {}

void BubbleSorter::sort(std::vector<int>& arr) {
    swaps = 0;
    for (const auto& [a, b] : swapPairs) {
        if (a < arr.size() && b < arr.size() && arr[a] > arr[b]) {
            std::swap(arr[a], arr[b]);
            swaps++;
        }
    }
}

std::vector<std::pair<int, int>> BubbleSorter::generateSwapPairs(int n) {
    swapPairs.clear();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            swapPairs.emplace_back(j, j + 1);
        }
    }
    return swapPairs;
}

int BubbleSorter::getMaxSwaps() const {
    return swapPairs.size();
}

int BubbleSorter::depth(const std::vector<int>& arr) const {
    return arr.size() - 1;
}
