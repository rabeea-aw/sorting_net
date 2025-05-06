#include "Data_sort.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // for min_element

#define GREEN "\033[32m"
#define RESET "\033[0m"

using namespace std;

int main() {
    try {
        vector<std::string> sorters = {"bitonic", "merge", "bubble"};
        int size = 16;
        const std::string output_file = "/Users/rabeea/Library/Mobile Documents/com~apple~CloudDocs/tel_hai/Season 7/proj_1/proj_1/sorting_network_results.csv"; // Absolute path
        
        ofstream outFile(output_file);
        
        if (!outFile.is_open()) {
            throw std::runtime_error("Failed to open output file: " + output_file);
        }
        
        std::cout << output_file << "\n";
        
        outFile << "Size,Sorter,IsValid,MaxSwaps,Depth,IsMinDepth\n"; // New column
        
        for (int n = 1; n <= size; ++n) {
            vector<int> depths;
            vector<bool> is_valid_list;
            vector<int> max_swaps;
            vector<string> sorter_names;
            
            // First pass: Collect data
            for (const auto& sorter : sorters) {
                cout << "Testing sorter: " << sorter << "\n";
                Data_sort ds(n, sorter);
                
                bool valid = ds.check();
                cout << "  Sorting network is " << (valid ? "valid" : "invalid") << "\n";
                cout << "  Max swaps: " << ds.size() << "\n";
                cout << "  Depth: " << ds.depth() << "\n\n";
                
                depths.push_back(ds.depth());
                is_valid_list.push_back(valid);
                max_swaps.push_back(ds.size());
                sorter_names.push_back(sorter);
            }
            
            // Find minimum depth (only among valid sorters)
            int min_depth = -1;
            for (size_t i = 0; i < depths.size(); ++i) {
                if (is_valid_list[i] && (min_depth == -1 || depths[i] < min_depth)) {
                    min_depth = depths[i];
                }
            }
            
            // Second pass: Write to CSV (marking the min depth)
            for (size_t i = 0; i < sorter_names.size(); ++i) {
                outFile << n << ","
                        << sorter_names[i] << ","
                        << (is_valid_list[i] ? "yes" : "no") << ","
                        << max_swaps[i] << ","
                        << depths[i] << ","
                        << ((depths[i] == min_depth && is_valid_list[i]) ?  "yes"  : "no") << "\n";
            }
        }
        
        cout << "CSV file generated successfully with min depth markers.\n";
    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
