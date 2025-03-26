#ifndef BITONIC_SORTER_HPP
#define BITONIC_SORTER_HPP

#include <vector>

#include <climits> // for INT_MAX
using namespace std;
class BitonicSorter {
private:
    vector<pair<int, int>> swapPairs;
    int maxSwaps;

    bool isPowerOf2(int n);
    int nextPowerOf2(int n);
    void bitonicMerge(vector<int>& arr, int low, int cnt, bool dir);
    void bitonicSort(vector<int>& arr, int low, int cnt, bool dir);

public:
    BitonicSorter();
    
    void sort(vector<int>& arr);
    int depth(vector<int>& arr);
    int getMaxSwaps() const;
    const vector<std::pair<int, int>>& getSwapPairs() const;
};

#endif // BITONIC_SORTER_HPP
