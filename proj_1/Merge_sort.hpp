#ifndef MERGE_SORTER_HPP
#define MERGE_SORTER_HPP

#include "Sorter.hpp"
#include <vector>
#include <utility>

class MergeSorter : public Sorter {
private:
    mutable int maxSwaps;
    mutable std::vector<std::pair<int, int>> swapPairs;

    void mergeSort(int lo, int n);
    void merge(int lo, int n);
    bool isPowerOf2(int n) const;
    int nextPowerOf2(int n) const;

public:
    MergeSorter();
    void sort(std::vector<int>& arr) override;
    std::vector<std::pair<int, int>> generateSwapPairs(int n) override;
    int getMaxSwaps() const override;
    int depth(const std::vector<int>& arr) const override;
};

#endif
