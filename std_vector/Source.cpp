#include <iostream>
#include "Std_vector.h"

int main() {
	int n = 3;
	Vector a;
	std::cout << "Vector a: " << std::endl;
	a.print();
	Vector b(n);
	std::cout << "Vector b: " << std::endl;
	b.print();
	Vector c(n, 1);
	std::cout << "Vector c: " << std::endl;
	c.print();
	std::cout << std::endl;

	//empty
	if (a.empty()) {
		std::cout << "vector a is empty" << std::endl;
	} 
	else {
		std::cout << "vector a is not empty" << std::endl;
	}

	if (b.empty()) {
		std::cout << "vector b is empty" << std::endl;
	}
	else {
		std::cout << "vector b is not empty" << std::endl;
	}
	std::cout << std::endl;

	//operator=
	std::cout << "#operator=" << std::endl;
	std::cout << "a=b" << std::endl;
	a = b;
	std::cout << "Vector a: " << std::endl;
	a.print();
	std::cout << "" << std::endl;

	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i+1;
	}

	Vector v(n, arr);
	std::cout << "Vector v: " << std::endl;
	v.print();
	std::cout << "Size v: " << v.size() << std::endl;
	std::cout<< "Capacity v: " << v.get_capacity()<< std::endl;
	std::cout << "" << std::endl;

	//operator[]
	std::cout << "#operator[]" << std::endl;
	std::cout << "v[1]" << std::endl;
	std::cout << v[1] << std::endl;
	std::cout <<  std::endl;

	// pop_back
	v.pop_back();
	std::cout << "#pop_back v:" << std::endl;
	v.print();
	std::cout << "Size v: " << v.size() << std::endl;
	std::cout << "Capacity v: " << v.get_capacity() << std::endl;
	std::cout << std::endl;

	// insert
	v.insert(1, 5);
	std::cout << "#v pos 1 insert 5:" << std::endl;
	v.print();
	std::cout << "Size v: " << v.size() << std::endl;
	std::cout << "Capacity v: " << v.get_capacity() << std::endl;
	std::cout << std::endl;

	int len_array = n + 1;
	double* array = new double[len_array];
	std::cout << "array: ";
	for (int i = 0; i < len_array; i++) {
		array[i] = i + 1;
		std::cout << array[i]<<" ";
	}
	std::cout << std::endl;

	v.insert(1, array, len_array);
	std::cout << "#v pos 1 insert array:" << std::endl;
	v.print();
	std::cout << "Size v: " << v.size() << std::endl;
	std::cout << "Capacity v: " << v.get_capacity() << std::endl;
	std::cout << std::endl;

	b.insert(1, c);
	std::cout << "#b pos 1 insert vector c:" << std::endl;
	b.print();
	std::cout << "Size b: " << b.size() << std::endl;
	std::cout << "Capacity b: " << b.get_capacity() << std::endl;
	std::cout << std::endl;

	// push_back
	b.push_back(0);
	std::cout << "#b push_back 0:" << std::endl;
	b.print();
	std::cout << "Size b: " << b.size() << std::endl;
	std::cout << "Capacity b: " << b.get_capacity() << std::endl;
	std::cout << std::endl;

	// erase
	b.erase(1);
	std::cout << "#b erase pos 1:" << std::endl;
	b.print();
	std::cout << "Size b: " << b.size() << std::endl;
	std::cout << "Capacity b: " << b.get_capacity() << std::endl;
	std::cout << std::endl;

	b.erase(3, 2);
	std::cout << "#b erase 2 elem pos 3:" << std::endl;
	b.print();
	std::cout << "Size b: " << b.size() << std::endl;
	std::cout << "Capacity b: " << b.get_capacity() << std::endl;
	std::cout << std::endl;

	//push_back
	v.push_back(4);
	std::cout << "#v push_back 4:" << std::endl;
	v.print();
	std::cout << "Size v: " << v.size() << std::endl;
	std::cout << "Capacity v: " << v.get_capacity() << std::endl;
	std::cout << std::endl;

	delete[] arr;
	delete[] array;
	return 0;
}