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
    vector<pair<int, int>> swapPairs;
    int maxSwaps;

public:
    BubbleSorter();
    
    void sort(vector<int>& arr);
    int depth(vector<int>& arr);
    int getMaxSwaps() const;
    const vector<pair<int, int>>& getSwapPairs() const;
};
#endif /* BubbleSort_hpp */
