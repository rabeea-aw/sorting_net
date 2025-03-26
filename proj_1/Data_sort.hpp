#ifndef DATA_SORT_HPP
#define DATA_SORT_HPP

#include "Sorter.hpp"
#include <string>

class Data_sort {
private:
    int n;
    int max_depth;
    int maxswap;
    bool isk;
    std::string activeSorter;
    Sorter* sorter;

    std::vector<int> generateMutation(int i, int n);

public:
    Data_sort(int n, std::string sorterName);
    ~Data_sort();
    bool check();
    int size();
    int depth();
    bool is_ok();
};

#endif
