#ifndef ODDEVEN_SORTER_HPP
#define ODDEVEN_SORTER_HPP

#include "Sorter.hpp"
#include <vector>
#include <utility>

class OddEvenSorter : public Sorter {
private:
    mutable int swaps;
    std::vector<std::pair<int, int>> swapPairs;

public:
    OddEvenSorter();
    void sort(std::vector<int>& arr) override;
    std::vector<std::pair<int, int>> generateSwapPairs(int n) override;
    int getMaxSwaps() const override;
    int depth(const std::vector<int>& arr) const override;
};

#endif
