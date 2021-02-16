#include "int_array.h"

dsc::IntArray::IntArray(std::size_t size) : array_{new int[size]{}}, size_{size} {}

dsc::IntArray::~IntArray() {
    delete [] array_;
    }

dsc::IntArray::IntArray(const IntArray& original) : array_{new int[original.size()]{}}, size_{original.size()} {
    for (std::size_t i = 0; i < size(); ++i) {
        array_[i] = original.array_[i];
    }
}

bool dsc::IntArray::operator!=(const dsc::IntArray& other) const {
    return !(*this == other);
}

bool dsc::IntArray::operator==(const dsc::IntArray& other) const {
    if (size() != other.size()) {
        return false;
    }

    for(std::size_t i = 0; i < size(); i++) {
        if (array_[i] != other.array_[i]) {
            return false;
        }
    }
    return true;
}

int& dsc::IntArray::operator[](std::size_t i) {
    return array_[i];
}

const int& dsc::IntArray::operator[](std::size_t i) const {
    return array_[i];
}

dsc::IntArray& dsc::IntArray::operator=(const dsc::IntArray& other) {
    if (this == &other) {
        return *this;
    }

    size_ = other.size_;

    delete [] array_;
    array_ = new int[size_]{};

    for (std::size_t i = 0; i < size(); ++i) {
        (*this)[i] = other[i];
    }

    return *this;
}