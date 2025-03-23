//
//  OddEvenSorter.hpp
//  proj_1
//
//  Created by Rabeea on 26/03/2025.
//

#ifndef OddEvenSorter_hpp
#define OddEvenSorter_hpp

#include <stdio.h>
#include <vector>

class OddEvenSorter {
public:
    OddEvenSorter();
    
    void sort(std::vector<int>& arr);
    int depth(std::vector<int>& arr);
    int getMaxSwaps() const;
    const std::vector<std::pair<int, int>>& getSwapPairs() const;

private:
    int maxSwaps;                         // Total number of swaps
    std::vector<std::pair<int, int>> swapPairs; // Record of swap pairs
    
    // Helper functions
    bool isPowerOf2(int n);
    int nextPowerOf2(int n);
    void oddEvenSort(std::vector<int>& arr, int low, int n); // Renamed from batcherSort
};
#endif /* OddEvenSorter_hpp */
