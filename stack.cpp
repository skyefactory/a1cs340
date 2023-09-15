#include "stack.h"
#include <string>
Stack::Stack() {
	// -1 means empty so init to top var to -1.
	top = -1;
}

bool Stack::isEmpty() {
	// -1 means empty
	if (top == -1) {
		return true;
	}
	return false;
}

bool Stack::isFull() {
	if (top == MAX - 1) {
		return true;
	}
	return false;
}

bool Stack::push(std::string x) {
	if (isFull()) {
		return false;
	}
	top++;
	array[top] = x;
	return true;
}

std::string Stack::pop()
{
	if (!isEmpty()) {
		std::string x = array[top];
		top--;
		return x;
	}
	return "";
}

std::string Stack::peek() {
	return array[top];

}