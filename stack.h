#pragma once
#include <string>
#include "node.h"
const int MAX = 100;
template <typename T> class Stack {
private:
	int top;
	T array[MAX];
public:
	Stack();
	bool push(T x);
	T pop();
	T peek();
	bool isEmpty();
	bool isFull();
};

