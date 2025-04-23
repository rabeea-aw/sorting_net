#include "Data_sort.hpp"
#include "bitonic_sorter.hpp"
#include "Merge_sort.hpp"
#include "BubbleSort.hpp"
#include "Data_sort.hpp"
#include <stdexcept>
#include <iostream>

Data_sort::Data_sort(int n, std::string sorterName) : n(n), max_depth(0), maxswap(0), isk(false), activeSorter(sorterName),totalCombinations(1ULL << n) {
    if (sorterName == "bitonic") {
//        sorter = new BitonicSorter();
        allSwapPairs=(new BitonicSorter())->generateSwapPairs(n);
    } else if (sorterName == "merge") {
//        sorter = new MergeSorter();
        allSwapPairs=(new MergeSorter())->generateSwapPairs(n);
    } else if (sorterName == "bubble") {
//        sorter = new BubbleSorter();
        allSwapPairs=(new BubbleSorter())->generateSwapPairs(n);
    } else {
        throw std::invalid_argument("Unknown sorter: " + sorterName);
    }
}

Data_sort::~Data_sort() {
//    delete sorter;
}

std::vector<int> Data_sort::generateMutation(long int i, int n) {
    
    std::vector<int> mutation(n);
    for (int j = 0; j < n; j++) {
        mutation[j] = (i >> j) & 1;
    }
    
    return mutation;
}

bool Data_sort::check() {

    for (long int i = 0; i < totalCombinations; i++) {
        std::vector<int> mutation = generateMutation(i, n);
        try {
            // Apply all swap pairs
            for (const auto& pair : allSwapPairs) {
//                std::cout << "(" << pair.first << ",fffff " << pair.second << ")\n";
                if ( mutation[pair.first] > mutation[pair.second]) {
                    std::swap(mutation[pair.first], mutation[pair.second]);
                }
            }
            // Check if the mutation is sorted
            for (size_t j = 1; j < mutation.size(); j++) {
                if (mutation[j] < mutation[j - 1]) {
                    std::cout << i<<mutation[j - 1] <<"xxxxxxxxxxxxxxxxxxxxx";
                    isk = false;
                    return false;
                }
            }
        } catch (const std::exception& e) {
            isk = false;
            return false; // Sorting failed
        }
    }
    isk = true;
    return true;
}

int Data_sort::size() {
//    maxswap = sorter->getMaxSwaps();
    return allSwapPairs.size();
}

int Data_sort::depth() {
//    int size = 1 << n; // Number of elements = 2^n
        std::vector<int> depth(totalCombinations, 0); // Initialize depth[i] = 0
        int total_depth = 0;

        for (size_t j = 0; j < allSwapPairs.size(); ++j) {
            int i1 = allSwapPairs[j].first;
            int i2 = allSwapPairs[j].second;
            if (i1 >= totalCombinations || i2 >= totalCombinations) {
                throw std::out_of_range("Invalid comparator indices");
            }
            int new_depth = 1 + std::max(depth[i1], depth[i2]);
            depth[i1] = new_depth;
            depth[i2] = new_depth;
            total_depth = std::max(total_depth, new_depth);
        }

        max_depth = total_depth;
        return total_depth;
}

bool Data_sort::is_ok() {
    return isk;
}
