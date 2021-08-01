#include "int_array.h"
#include <stdexcept>

constexpr std::size_t DEFAULTCAP = 2;

dsc::IntArray::IntArray() : array_{new int[DEFAULTCAP]{}}, size_{0}, capacity_{DEFAULTCAP}{}

dsc::IntArray::IntArray(std::size_t size) : array_{new int[size]{}}, size_{size}, capacity_{size}{}

dsc::IntArray::~IntArray() {
    delete [] array_;
    }

dsc::IntArray::IntArray(const IntArray& original) : array_{new int[original.capacity()]{}}, size_{original.size()}, capacity_{original.capacity()} {
    for (std::size_t i = 0; i < size(); ++i) {
        array_[i] = original[i];
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

    size_ = other.size();
    capacity_ = other.capacity();

    delete [] array_;
    array_ = new int[capacity()]{};

    for (std::size_t i = 0; i < size(); ++i) {
        (*this)[i] = other[i];
    }

    return *this;
}

int& dsc::IntArray::at(std::size_t index) {
	if (index > size()) { // should I check if it's in bounds or out?
		throw std::out_of_range ("index out of array bounds");
	} else {
		return array_[index];
	}
}

int& dsc::IntArray::front() {
	return array_[0];
}

int& dsc::IntArray::back() {
	return array_[size() - 1];
}

int* dsc::IntArray::begin() {
	return array_;
}

int* dsc::IntArray::end() {
	return array_ + size() + 1;
}


const int* dsc::IntArray::begin() const {
	return array_;
}

const int* dsc::IntArray::end() const {
	return array_ + size();
}

void dsc::IntArray::reserve(std::size_t n) {
	if (n <= capacity_) {
		return;
	}
	capacity_ = n;
	int* resized_array = new int[capacity_];
	for(std::size_t i = 0; i < size(); ++i) {
		resized_array[i] = array_[i];
	}
	
	delete [] array_;
	array_ = resized_array;
}

int dsc::IntArray::pop_back() {
    int result = (*this)[size() - 1];
    (*this)[size() - 1] = 0;
    size_--;
    
    return result;
}

void dsc::IntArray::push_back(int value) {
	if (size() < capacity()) {
		reserve(capacity());
	}
		(*this)[size()] = value;
		size_++;
}

void dsc::IntArray::insert(int value, std::size_t index) {
	if (size() == capacity()) { reserve(capacity()); }
	for(std::size_t i = size() - 1; i > index; --i) {
		(*this)[i] = (*this)[i - 1];
	}
	size_++;
	(*this)[index] = value;
}
