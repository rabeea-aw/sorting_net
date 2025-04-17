#include "Data_sort.hpp"
#include <iostream>

int main() {
    try {
        std::vector<std::string> sorters = {"bitonic", "merge", "bubble", "odd"};
        int n = 16;

        for (const auto& sorter : sorters) {
            std::cout << "Testing sorter: " << sorter << "\n";
            Data_sort ds(n, sorter);

            if (ds.check()) {
                std::cout << "  Sorting network is valid (isk = " << ds.is_ok() << ")\n";
            } else {
                std::cout << "  Sorting network is invalid (isk = " << ds.is_ok() << ")\n";
            }

            std::cout << "  Max swaps: " << ds.size() << "\n";
            std::cout << "  Depth: " << ds.depth() << "\n\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
