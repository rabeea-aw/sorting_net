//
//  BubbleSort.cpp
//  project
//
//  Created by Rabeea on 13/03/2025.
//

#include "BubbleSort.hpp"

using namespace std;

BubbleSorter::BubbleSorter() : maxSwaps(0) {}

void BubbleSorter::sort(vector<int>& arr) {
    swapPairs.clear();
    if (arr.empty()) return;
    
    int n = arr.size();
    bool swapped;
    
    // Bubble sort implementation
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Record the swap pair
                swapPairs.push_back({j, j + 1});
                // Perform the swap
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
            else{
                swapPairs.push_back({j, j + 1});
            }
        }
        // If no swapping occurred, array is already sorted
        if (!swapped) break;
    }
    
    maxSwaps = static_cast<int>(swapPairs.size());
}

// Calculate depth (longest path from input to output)
int BubbleSorter::depth(vector<int>& arr) {
    if (arr.empty()) return 0;
    
    // For bubble sort, depth can be considered as the number of passes
    // In parallel implementation, it could be n-1 in worst case
    int n = (int)arr.size();
    return n - 1;  // Worst-case number of passes
}

int BubbleSorter::getMaxSwaps() const {
    return maxSwaps;
}

const vector<pair<int, int>>& BubbleSorter::getSwapPairs() const {
    return swapPairs;
}
