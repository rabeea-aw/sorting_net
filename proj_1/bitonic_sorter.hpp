#ifndef BITONIC_SORTER_HPP
#define BITONIC_SORTER_HPP

#include "Sorter.hpp"
#include <vector>
#include <utility>

class BitonicSorter : public Sorter {
private:
    mutable int maxSwaps;
    mutable std::vector<std::pair<int, int>> swapPairs;

    void generateBitonicPairs(int low, int cnt, bool dir);
    bool isPowerOf2(int n) const;
    int nextPowerOf2(int n) const;

public:
    BitonicSorter();
    void sort(std::vector<int>& arr) override;
    std::vector<std::pair<int, int>> generateSwapPairs(int n) override;
    int getMaxSwaps() const override;
    int depth(const std::vector<int>& arr) const override;
};

#endif
