#ifndef BITONIC_SORTER_HPP
#define BITONIC_SORTER_HPP

#include <vector>

#include <climits> // for INT_MAX

class BitonicSorter {
private:
    std::vector<std::pair<int, int>> swapPairs;
    int maxSwaps;

    bool isPowerOf2(int n);
    int nextPowerOf2(int n);
    void bitonicMerge(std::vector<int>& arr, int low, int cnt, bool dir);
    void bitonicSort(std::vector<int>& arr, int low, int cnt, bool dir);

public:
    BitonicSorter();
    
    void sort(std::vector<int>& arr);
    int depth(std::vector<int>& arr);
    int getMaxSwaps() const;
    const std::vector<std::pair<int, int>>& getSwapPairs() const;
};

#endif // BITONIC_SORTER_HPP
