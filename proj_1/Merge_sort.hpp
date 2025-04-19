#ifndef MERGE_SORTER_HPP
#define MERGE_SORTER_HPP

#include "Sorter.hpp"
#include <vector>
#include <utility>
using namespace std;
class MergeSorter : public Sorter {
private:
    mutable int maxSwaps;
    mutable vector<pair<int, int>> swapPairs;

    void oddEvenMerge(int lo, int n, int r);
    void oddEvenMergeSort(int lo, int n);
    bool isPowerOf2(int n) const;
    int nextPowerOf2(int n) const;

public:
    MergeSorter();
    void sort(std::vector<int>& arr) override;
    vector<pair<int, int>> generateSwapPairs(int n) override;
    int getMaxSwaps() const override;
    int depth(const vector<int>& arr) const override;
};

#endif
