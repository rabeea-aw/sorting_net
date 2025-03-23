//
//  BubbleSort.hpp
//  project
//
//  Created by Rabeea on 13/03/2025.
//

#ifndef BubbleSort_hpp
#define BubbleSort_hpp

#include <stdio.h>
#include <vector>
#include <algorithm> // For std::swap
#include <utility>
using namespace std;
class BubbleSorter {
private:
    std::vector<std::pair<int, int>> swapPairs;
    int maxSwaps;

public:
    BubbleSorter();
    
    void sort(std::vector<int>& arr);
    int depth(std::vector<int>& arr);
    int getMaxSwaps() const;
    const std::vector<std::pair<int, int>>& getSwapPairs() const;
};
#endif /* BubbleSort_hpp */
