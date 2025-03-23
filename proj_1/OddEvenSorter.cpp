//
//  OddEvenSorter.cpp
//  proj_1
//
//  Created by Rabeea on 26/03/2025.
//

#include "OddEvenSorter.hpp"
#include <algorithm>
#include <cmath>
#include <climits>

OddEvenSorter::OddEvenSorter() : maxSwaps(0) {}

bool OddEvenSorter::isPowerOf2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int OddEvenSorter::nextPowerOf2(int n) {
    return pow(2, ceil(log2(n)));
}

void OddEvenSorter::oddEvenSort(std::vector<int>& arr, int low, int n) {
    if (n <= 1) return;
    
    int m = n / 2;
    
    oddEvenSort(arr, low, m);
    oddEvenSort(arr, low + m, n - m);
    
    for (int p = 1; p < n; p *= 2) {
        for (int k = p; k >= 1; k /= 2) {
            for (int j = k % p; j <= n - 1 - k; j += 2 * k) {
                for (int i = 0; i <= std::min(k - 1, n - j - k - 1); i++) {
                    int idx1 = low + i + j;
                    int idx2 = low + i + j + k;
                    if (std::floor((i + j) / (p * 2.0)) == std::floor((i + j + k) / (p * 2.0))) {
                        if (arr[idx1] > arr[idx2]) {
                            swapPairs.push_back({idx1, idx2});
                            std::swap(arr[idx1], arr[idx2]);
                        } else {
                            swapPairs.push_back({idx1, idx2});
                        }
                    }
                }
            }
        }
    }
}

void OddEvenSorter::sort(std::vector<int>& arr) {
    swapPairs.clear();
    int n = arr.size();
    if (n <= 1) {
        maxSwaps = 0;
        return;
    }
    
    int newSize = nextPowerOf2(n);
    if (!isPowerOf2(n)) {
        arr.resize(newSize, INT_MAX);
    }
    
    oddEvenSort(arr, 0, arr.size());
    
    if (n != arr.size()) {
        arr.resize(n);
    }
    
    maxSwaps = swapPairs.size();
}

int OddEvenSorter::depth(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;
    
    int paddedSize = nextPowerOf2(n);
    int stages = log2(paddedSize);
    return stages * (stages + 1) / 2;
}

int OddEvenSorter::getMaxSwaps() const {
    return maxSwaps;
}

const std::vector<std::pair<int, int>>& OddEvenSorter::getSwapPairs() const {
    return swapPairs;
}
