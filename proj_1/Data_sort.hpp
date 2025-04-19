#ifndef DATA_SORT_HPP
#define DATA_SORT_HPP

#include "Sorter.hpp"
#include <string>
using namespace std;
class Data_sort {
private:
    int n;
    int max_depth;
    int maxswap;
    bool isk;
    string activeSorter;
    Sorter* sorter;

    vector<int> generateMutation(int i, int n);

public:
    Data_sort(int n, string sorterName);
    ~Data_sort();
    bool check();
    int size();
    int depth();
    bool is_ok();
};

#endif
