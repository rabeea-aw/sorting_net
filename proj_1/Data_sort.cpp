#include "Data_sort.hpp"
#include "bitonic_sorter.hpp"
#include "Merge_sort.hpp"
#include "BubbleSort.hpp"
#include "OddEvenSorter.hpp"
#include "Data_sort.hpp"
#include <stdexcept>
#include <iostream>

Data_sort::Data_sort(int n, std::string sorterName) : n(n), max_depth(0), maxswap(0), isk(false), activeSorter(sorterName) {
    if (sorterName == "bitonic") {
        sorter = new BitonicSorter();
    } else if (sorterName == "merge") {
        sorter = new MergeSorter();
    } else if (sorterName == "bubble") {
        sorter = new BubbleSorter();
    } else if (sorterName == "odd") {
        sorter = new OddEvenSorter();
    } else {
        throw std::invalid_argument("Unknown sorter: " + sorterName);
    }
}

Data_sort::~Data_sort() {
    delete sorter;
}

std::vector<int> Data_sort::generateMutation(int i, int n) {
    
    std::vector<int> mutation(n);
    for (int j = 0; j < n; j++) {
        mutation[j] = (i >> j) & 1;
    }
    return mutation;
}

bool Data_sort::check() {
    int totalCombinations = 1 << n;
    auto swapPairs = sorter->generateSwapPairs(n);

    for (int i = 0; i < totalCombinations; i++) {
        std::vector<int> mutation = generateMutation(i, n);
        try {
            // Apply all swap pairs
            for (const auto& pair : swapPairs) {
                if ( mutation[pair.first] > mutation[pair.second]) {
                    std::swap(mutation[pair.first], mutation[pair.second]);
                }
            }
            // Check if the mutation is sorted
            for (size_t j = 1; j < mutation.size(); j++) {
                if (mutation[j] < mutation[j - 1]) {
                    std::cout << j-1 <<"xxxxxxxxxxxxxxxxxxxxx";
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
    maxswap = sorter->getMaxSwaps();
    return maxswap;
}

int Data_sort::depth() {
    int totalCombinations = 1 << n;
    for (int i = 0; i < totalCombinations; i++) {
        std::vector<int> mutation = generateMutation(i, n);
        int current_depth = sorter->depth(mutation);
        if (current_depth > max_depth) {
            max_depth = current_depth;
        }
    }
    return max_depth;
}

bool Data_sort::is_ok() {
    return isk;
}
