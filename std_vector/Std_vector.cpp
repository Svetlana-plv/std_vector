#include <iostream>
#include "Std_vector.h"

const int factor = 2;

// constructors
Vector::Vector() {
	len = 0;
	capacity = 1;
	data = new double[capacity];
	this->data[0] = 0;
}

Vector::Vector(const int len, const double value) {
	this->len = len;
	this->capacity = len*factor;
	data = new double[capacity];
	for (int i = 0; i < len; i++) {
		this->data[i] = value;
	}
}

Vector::Vector(const int len, const double* arr) {
	this->len = len;
	this->capacity = len * factor;
	data = new double[capacity];
	for (int i = 0; i < len; i++) {
		this->data[i] = arr[i];
	}
}

Vector::Vector(const Vector& b) : capacity(b.capacity), len(b.len) {
	this->data = new double[this->capacity];
	for (int i = 0; i < this->len; i++) this->data[i] = b.data[i];
};


//operators
Vector& Vector::operator=(const Vector& v) {
	if (&v == this) return *this;
	this->capacity = v.capacity;
	this->len = v.len;
	delete[] this->data;
	this->data = new double[capacity];
	for (int i = 0; i < this->len; i++) {
		this->data[i] = v.data[i];
	}
	return *this;
}

double Vector::operator[](int ind)const {
	return data[ind];
}

double& Vector::operator[](int ind) {
	return data[ind];
}

// size of vector
int Vector::size()const {
	return len;
}

// get_capacity
int Vector::get_capacity()const {
	return capacity;
}

//erase
void Vector::erase(const int pos, const int n) {
	if (n > this->len - pos || pos > this->len) throw std::out_of_range("Index out of range!");
	this->len -= n;
	for (int i = pos; i < this->len + 1; i++) this->data[i] = this->data[n + i];
}

//insert_elem
void Vector::insert(const int pos, const double value) {
	if (pos > this->len) throw std::out_of_range("Index out of range!");
	(*this).resize(this->len + 1);
	for (int i = this->len+1; i > pos; i--) this->data[i] = this->data[i-1];
	this->data[pos] = value;
}

//insert_n_elements
void Vector::insert(const int pos, const double* arr, const int n) {
	if (pos > this->len) throw std::out_of_range("Index out of range!");
	(*this).resize(this->len + n);
	for (int i = this->len - 1; i >= pos + n; i--)	this->data[i] = this->data[i - n];
	for (int i = 0; i < n; i++) this->data[pos + i] = arr[i];
}

//insert_vector
void Vector::insert(const int pos, const Vector v) {
	if (pos > this->len) throw std::out_of_range("Index out of range!");
	(*this).resize(this->len + v.len);
	for (int i = this->len-1; i >= pos + v.len; i--) this->data[i] = this->data[i - v.len];
	for (int i = 0; i < v.len; i++) this->data[pos + i] = v.data[i];
}


//pop_back
void Vector::pop_back() {
	if (this->len<=0) throw std::out_of_range("Index out of range!");
	this->len -= 1;
}

//push_back
void Vector::push_back(const double value) {
	if (this->len <= 0) throw std::out_of_range("Index out of range!");
	(*this).resize(this->len + 1);
	this->data[this->len-1]=value;
}

//resize
void Vector::resize(const int len_new) {
	if (len_new < 0) throw std::exception();
	else if (len_new>this->capacity) {
		this->capacity = len_new * factor;
		double* data_new = new double[this->capacity];
		for (int i = 0; i < this->len; i++) {
			data_new[i] = this->data[i];
		}
		delete[] this->data;
		data = data_new;
		this->len = len_new;
	}
	else {
		this->len = len_new;
	}

}

// empty vector
bool Vector::empty()const {
	if (len) {
		return false;
	}
	else {
		return true;
	}
}

// print vector
void Vector::print()const {
	for (int i = 0; i < len; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

// destructor
Vector::~Vector() {
	delete[] data;
}