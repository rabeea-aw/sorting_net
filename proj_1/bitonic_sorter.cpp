#include "bitonic_sorter.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
BitonicSorter::BitonicSorter() : maxSwaps(0) {}

// Helper function to check if a number is power of 2
bool BitonicSorter::isPowerOf2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// Helper function to get next power of 2
int BitonicSorter::nextPowerOf2(int n) {
    return pow(2, ceil(log2(n)));
}

// Bitonic merge
void BitonicSorter::bitonicMerge(vector<int>& arr, int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++) {
            if ((arr[i] > arr[i + k]) == dir) {
                swapPairs.push_back({i, i + k});
                swap(arr[i], arr[i + k]);
            }
            else{
                swapPairs.push_back({i, i + k});
            }
        }
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

// Bitonic sort recursive
void BitonicSorter::bitonicSort(vector<int>& arr, int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonicSort(arr, low, k, true);      // sort in ascending order
        bitonicSort(arr, low + k, k, false);  // sort in descending order
        bitonicMerge(arr, low, cnt, dir);
    }
}

void BitonicSorter::sort(vector<int>& arr) {
    swapPairs.clear();
    int n = arr.size();
    
    // If n is not power of 2, pad with INT_MAX
    int newSize = nextPowerOf2(n);
    if (!isPowerOf2(n)) {
        arr.resize(newSize, INT_MAX);
    }

    // Perform bitonic sort
    bitonicSort(arr, 0, arr.size(), true);
    
    // Trim back to original size if padded
    if (n != arr.size()) {
        arr.resize(n);
    }
    
    maxSwaps = swapPairs.size();
}

// Calculate depth (longest path from input to output)
int BitonicSorter::depth(vector<int>& arr) {
    int n = arr.size();
    int paddedSize = nextPowerOf2(n);
    
    // Depth of bitonic sort is log2(n) * (log2(n) + 1) / 2
    int stages = log2(paddedSize);
    return stages * (stages + 1) / 2;
}

int BitonicSorter::getMaxSwaps() const {
    return maxSwaps;
}

const vector<pair<int, int>>& BitonicSorter::getSwapPairs() const {
    return swapPairs;
}
