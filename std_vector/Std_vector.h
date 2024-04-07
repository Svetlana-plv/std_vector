#pragma once
#include <iostream>

class Vector {
private:
	double* data = nullptr;
	int capacity = 0;
	int len = 0;

public:
	// constructors
	Vector(); //default constructor
	Vector(const int capasity, const double value=0);
	Vector(const int len, const double* arr);
	Vector(const Vector& b); // copy constructor
	~Vector();	// destructor

	// operators
	Vector& operator=(const Vector& v);
	double operator[](int ind)const;
	double& operator[](int ind);

	
	int size()const;	// size of vector
	int get_capacity()const; // get_capacity

	void erase(const int pos, const int n=1); // erase
	void insert(const int pos, const double value); // insert_elem
	void insert(const int pos, const double* arr, const int n); // insert_n_elements
	void insert(const int pos, const Vector v); // insert_vector
	void pop_back(); //pop_back
	void push_back(const double value); //push_back

	bool empty()const;// empty vector
	void print()const;// print vector

private:
	void resize(const int len_new); //change_capacity
};