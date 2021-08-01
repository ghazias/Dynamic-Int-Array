#include <iostream>
#include "int_array.h"
#include <assert.h>

namespace {
	void create_array_test() {
		dsc::IntArray array(5);
		assert(array.size() == 5);
	}
	
	void reserve_test() {
		dsc::IntArray array(12);
		assert(array.capacity() == 12);
		
		array.reserve(16);
		assert(array.capacity() == 16);
	}
	
	void pop_back_test() {
		dsc::IntArray array(3);
		assert(array.size() == 3);
		
		array[0] = 28;
		array[1] = 2;
		array[2] = 85;
		
		int pop_val = array.pop_back();
		assert(pop_val == 85);
		assert(array.size() == 2);
		
		pop_val = array.pop_back();
		assert(pop_val == 2);
		assert(array.size() == 1);

		pop_val = array.pop_back();
		assert(pop_val == 28);
		assert(array.size() == 0);
	}
	
	void push_back_test() {
		dsc::IntArray array(3);
		assert(array.size() == 3);
		
		array[0] = 28;
		array[1] = 2;
		array[2] = 85;
		
		array.push_back(391);
		assert(array.size() == 4);
		assert(array.capacity() == 6);
		assert(array[3] == 291);
		
		dsc::IntArray empty_array(0);
		assert(empty_array.size() == 0);
		
		empty_array.push_back(39);
		assert(empty_array[0] == 39);
	}
	
	void insert_test() {
		dsc::IntArray array(3);
		assert(array.size() == 3);
		
		array[0] = 18;
		array[1] = 954;
		array[2] = 1;
		
		array.insert(73, 1);
		assert(array[1] == 73);
		assert(array.size() == 4);
	}
	
	void foe_reach_test() {
		dsc::IntArray array(3);
		assert(array.size() == 3);
		
		array[0] = 18;
		array[1] = 954;
		array[2] = 1;
		
		
		for(auto p : array) {
			std::cout << array[p] << '\n';
		}
	}
} // namespace

int main() {
	//create_array_test();
	//reserve_test();
	foe_reach_test();
}