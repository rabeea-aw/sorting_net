#include "Data_sort.hpp"
#include <iostream>
using namespace std;
int main() {
    try {
        vector<std::string> sorters = {"bitonic", "merge", "bubble"};
        int n = 22;

        for (const auto& sorter : sorters) {
            cout << "Testing sorter: " << sorter << "\n";
            Data_sort ds(n, sorter);

            if (ds.check()) {
                cout << "  Sorting network is valid (isk = " << ds.is_ok() << ")\n";
            } else {
                std::cout << "  Sorting network is invalid (isk = " << ds.is_ok() << ")\n";
            }

            cout << "  Max swaps: " << ds.size() << "\n";
            cout << "  Depth: " << ds.depth() << "\n\n";
        }
    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
