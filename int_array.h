#ifndef INT_ARRAY_H_
#define INT_ARRAY_H_

#include <cstddef>

namespace dsc {
class IntArray {
    public:
        IntArray(std::size_t size);
        ~IntArray();
        IntArray(const IntArray& original);
        int& operator[](std::size_t i);
        const int& operator[](std::size_t i) const;
        bool operator!=(const dsc::IntArray& other) const;
        bool operator==(const dsc::IntArray& other) const;
        IntArray& operator=(const dsc::IntArray& other);
        std::size_t size() const {return size_;}
        // void reserve(std::size_t new_capacity)
        // int capacity()
        // int pop_back
        // void push_back(int)
        // void insert(std::size_t index, int value)
        // 
    private:
        int* array_;
        std::size_t size_;
    };
} // namespace dsc

#endif