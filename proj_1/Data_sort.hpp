//
//  Data_sort.hpp
//  project
//
//  Created by Rabeea on 09/03/2025.
//

#ifndef Data_sort_hpp
#define Data_sort_hpp


#include <stdio.h>
#include <vector>
#include <utility>
#include "bitonic_sorter.hpp"
#include "Merge_sort.hpp"
#include "BubbleSort.hpp"
#include "OddEvenSorter.hpp"

using namespace std;
class Data_sort {
public:
    Data_sort(int n,string sorterName);
    bool cheek(); // Changed to use internal allGen
    int size();   // Returns max swaps
    int depth();  // Returns max depth
    bool is_ok(); // Returns isk status

private:
    std::vector<std::vector<int>> allGen;
    int max_depth;
    int maxswap;
    bool isk;
    string activeSorter;
    BitonicSorter sorter;                // Member sorter object
    MergeSorter mergeSorter;            // Merge sorter object
    BubbleSorter bubblSort;
    OddEvenSorter oddSort;

    void generateMutations(int n);
};
#endif /* Data_sort_hpp */
