#pragma once
#include <string>
const int MAX = 100;
class Stack {
private:
	int top;
	std::string array[MAX];
public:
	Stack();
	bool push(std::string x);
	std::string pop();
	std::string peek();
	bool isEmpty();
	bool isFull();
};