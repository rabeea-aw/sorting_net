

#ifndef Merge_sort_hpp
#define Merge_sort_hpp

#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

class MergeSorter {
private:
    int maxSwaps;
    vector<pair<int, int>> swapPairs;
    
    void merge(vector<int>& arr, int left, int mid, int right);
    void mergeSort(vector<int>& arr, int left, int right);

public:
    MergeSorter();
    
    void sort(vector<int>& arr);
    int depth(vector<int>& arr);
    int getMaxSwaps() const;
    const vector<std::pair<int, int>>& getSwapPairs() const;
};

#endif /* Merge_sort_hpp */
