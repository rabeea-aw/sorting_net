#include <iostream>
#include <vector>
#include "bitonic_sorter.hpp"
#include "Merge_sort.hpp"
#include "BubbleSort.hpp"
#include "Data_sort.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    
    
        
    Data_sort ds_bitonic(16, "bitonic");
        if ( ds_bitonic.cheek()) {
            cout <<"The size is "<< 16<< " Bitonic Sorter - Swaps: " << ds_bitonic.size()
                        << ", Depth: " << ds_bitonic.depth() << "\n";
        } else {
            cout << "Bitonic failed\n";
        }

    Data_sort ds_merge(8, "merge");
        if ( ds_merge.cheek()) {
            cout <<"The size is "<< 8<< " merge Sorter - Swaps: " << ds_merge.size()
                        << ", Depth: " << ds_merge.depth() << "\n";
        } else {
            cout << "merge failed\n";
        }
        
    Data_sort ds_buble(16, "buble");
        if ( ds_buble.cheek()) {
            cout <<"The size is "<< 16<< " buble Sorter - Swaps: " << ds_buble.size()
                        << ", Depth: " << ds_buble.depth() << "\n";
        } else {
            cout << "buble failed\n";
        }
        
    
    Data_sort ds_oddeven(8, "odd");
        if (ds_oddeven.cheek()) {
            cout <<"The size is "<< 8 << " Odd-Even Mergesort - Swaps: " << ds_oddeven.size()
                      << ", Depth: " << ds_oddeven.depth() << "\n";
        } else {
            cout << "Odd-Even failed\n";
        }
    

    return 0;
}
