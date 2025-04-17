#ifndef MERGE_SORTER_HPP
#define MERGE_SORTER_HPP

#include "Sorter.hpp"
#include <vector>
#include <utility>

class MergeSorter : public Sorter {
private:
    mutable int maxSwaps;
    mutable std::vector<std::pair<int, int>> swapPairs;
    std::vector<int> arr; // Temporary storage for the array being sorted

    void generateMergePairs(int low, int cnt);
    void merge(int lo1, int n1, int lo2, int n2);
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
