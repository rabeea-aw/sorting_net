//
//  Data_sort.cpp
//  project
//
//  Created by Rabeea on 09/03/2025.
//

#include "Data_sort.hpp"
#include <iostream>
#include <vector>
#include <utility>
//#include "bitonic_sorter.hpp"



using namespace std;

// Constructor
Data_sort::Data_sort(int n,string sorterName) {
    max_depth = 0;
    maxswap = 0;
    isk = false;
    activeSorter = sorterName;
    generateMutations(n);  // Generate all possible swap pairs
}

void Data_sort::generateMutations(int n) {
    int totalCombinations = 1 << n; // 2^n
    
    for (int i = 0; i < totalCombinations; i++) {
        std::vector<int> mutation(n);
        
        for (int j = 0; j < n; j++) {
            mutation[j] = (i >> j) & 1; // Extract the j-th bit
        }
        allGen.push_back(mutation);
        
//        std::cout << "Mutation " << i << ": [";
//                for (int k = 0; k < n; k++) {
//                    std::cout << mutation[k];
//                    if (k < n - 1) std::cout << ", ";
//                }
//                std::cout << "]\n";
                
            }
    }

bool Data_sort::cheek() {
    if (allGen.empty()) return false;
    
    int n = allGen[0].size();
    if (allGen.size() != (1 << n)) {
        isk = false;
        return false;
    }
    
    // Check each mutation has correct length and valid values
    for (const auto& mutation : allGen) {
        if (mutation.size() != n) {
            isk = false;
            return false;
        }
        for (int val : mutation) {
            if (val != 0 && val != 1) {
                isk = false;
                return false;
            }
        }
    }
    if(activeSorter == "bitonic") {
        for (auto mutation : allGen) { // Copy to preserve original
            try {
                sorter.sort(mutation);
                for (size_t i = 1; i < mutation.size(); i++) {
                    if (mutation[i] < mutation[i-1]) {
                        isk = false;
                        return false;  // Not properly sorted
                    }
                }
            }
            catch (const std::exception& e) {
                isk = false;
                return false;  // Bitonic sort failed
            }
        }
        isk = true;
        return true;  // All checks passed
    }
    
    if (activeSorter == "merge") {
        for (auto mutation : allGen) { // Copy to preserve original
            try {
                mergeSorter.sort(mutation);
                for (size_t i = 1; i < mutation.size(); i++) {
                    if (mutation[i] < mutation[i-1]) {
                        isk = false;
                        return false;  // Not properly sorted
                    }
                }
            }
            catch (const std::exception& e) {
                isk = false;
                return false;  // Bitonic sort failed
            }
        }
        isk = true;
        return true;  // All checks passed
    }
    
    if (activeSorter == "buble") {
        for (auto mutation : allGen) { // Copy to preserve original
            try {
                bubblSort.sort(mutation);
                for (size_t i = 1; i < mutation.size(); i++) {
                    if (mutation[i] < mutation[i-1]) {
                        isk = false;
                        return false;  // Not properly sorted
                    }
                }
            }
            catch (const std::exception& e) {
                isk = false;
                return false;  // Bitonic sort failed
            }
        }
        isk = true;
        return true;  // All checks passed
    }
    
    if (activeSorter == "odd") {
        for (auto mutation : allGen) { // Copy to preserve original
            try {
                oddSort.sort(mutation);
                for (size_t i = 1; i < mutation.size(); i++) {
                    if (mutation[i] < mutation[i-1]) {
                        isk = false;
                        return false;  // Not properly sorted
                    }
                }
            }
            catch (const std::exception& e) {
                isk = false;
                return false;  // Bitonic sort failed
            }
        }
        isk = true;
        return true;  // All checks passed
    }
    
    isk = false;
    return false;
}

int Data_sort::size() {
    if (activeSorter == "bitonic") {
    for (auto mutation : allGen) {
            sorter.sort(mutation);
            int current_swaps = sorter.getMaxSwaps();
            if (current_swaps > maxswap) {
                maxswap = current_swaps;
            }
        }

    }
    if (activeSorter == "merge") {
    for (auto mutation : allGen) {
        mergeSorter.sort(mutation);
            int current_swaps = mergeSorter.getMaxSwaps();
            if (current_swaps > maxswap) {
                maxswap = current_swaps;
            }
        }

    }
    
    if (activeSorter == "buble") {
    for (auto mutation : allGen) {
        bubblSort.sort(mutation);
            int current_swaps = bubblSort.getMaxSwaps();
            if (current_swaps > maxswap) {
                maxswap = current_swaps;
            }
        }

    }
    if (activeSorter == "odd") {
    for (auto mutation : allGen) {
        oddSort.sort(mutation);
        int current_swaps = oddSort.getMaxSwaps();
            if (current_swaps > maxswap) {
                maxswap = current_swaps;
            }
        }

    }
    
    return maxswap;  // Return the maximum swaps observed
}



int Data_sort::depth() {
    if (activeSorter == "bitonic") {
        for (auto mutation : allGen) { // Copy to avoid modifying allGen
            int current_depth = sorter.depth(mutation);  // Calculate depth for this mutation
            
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        }
    }
    
    if (activeSorter == "merge") {
        for (auto mutation : allGen) { // Copy to avoid modifying allGen
            int current_depth = mergeSorter.depth(mutation);  // Calculate depth for this mutation
            
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        }
    }
    
    if (activeSorter == "buble") {
        for (auto mutation : allGen) { // Copy to avoid modifying allGen
            int current_depth = bubblSort.depth(mutation);  // Calculate depth for this mutation
            
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        }
    }
    
    if (activeSorter == "odd") {
        for (auto mutation : allGen) { // Copy to avoid modifying allGen
            int current_depth = oddSort.depth(mutation);  // Calculate depth for this mutation
            
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        }
    }
    
    return max_depth;  // Return the maximum depth observed
}


bool Data_sort::is_ok() {
    return isk;
}
