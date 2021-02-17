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
        std::size_t capacity() const {return capacity_;};
        
        void reserve(std::size_t n); // increases array capacity by n
        int pop_back(); // removes and returns last value in array
        void push_back(int value); // adds value at rear of array
        void insert(int value, std::size_t index); // adds value at index
    private:
        int* array_; // pointer to data
        std::size_t size_; // actual elements
        std::size_t capacity_; // total elements
    };
} // namespace dsc

#endif