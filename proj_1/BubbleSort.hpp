//
//  BubbleSort.hpp
//  project
//
//  Created by Rabeea on 13/03/2025.
//

#ifndef BUBBLE_SORTER_HPP
#define BUBBLE_SORTER_HPP

#include "Sorter.hpp"
#include <vector>
#include <utility>

class BubbleSorter : public Sorter {
private:
    mutable int swaps;
    std::vector<std::pair<int, int>> swapPairs;

public:
    BubbleSorter();
    void sort(std::vector<int>& arr) override;
    std::vector<std::pair<int, int>> generateSwapPairs(int n) override;
    int getMaxSwaps() const override;
    int depth(const std::vector<int>& arr) const override;
};

#endif
