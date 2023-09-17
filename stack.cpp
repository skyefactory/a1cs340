#include "stack.h"
template <typename T> Stack<T>::Stack() {
	// -1 means empty so init to top var to -1.
	top = -1;
}

template <typename T> bool Stack<T>::isEmpty() {
	// -1 means empty
	if (top == -1) {
		return true;
	}
	return false;
}

template <typename T> bool Stack<T>::isFull() {
	if (top == MAX - 1) {
		return true;
	}
	return false;
}

template <typename T> bool Stack<T>::push(T x) {
	if (isFull()) {
		return false;
	}
	top++;
	array[top] = x;
	return true;
}

template <typename T> T Stack<T>::pop()
{
	if (!isEmpty()) {
		T x = array[top];
		top--;
		return x;
	}
}

template <typename T> T Stack<T>::peek() {
	return array[top];

}

template class Stack<int>;
template class Stack<std::string>;
template class Stack<Node*>;
