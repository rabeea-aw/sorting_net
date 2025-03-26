#ifndef SORTER_HPP
#define SORTER_HPP

#include <vector>
#include <utility>

class Sorter {
public:
    virtual void sort(std::vector<int>& arr) = 0;
    virtual std::vector<std::pair<int, int>> generateSwapPairs(int n) = 0;
    virtual int getMaxSwaps() const = 0;
    virtual int depth(const std::vector<int>& arr) const = 0;
    virtual ~Sorter() = default;
};

#endif
