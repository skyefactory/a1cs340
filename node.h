#pragma once

class Node {
private:
		char datum;
		Node* left;
		Node* right;
public:
		Node();
		Node(char data);
		Node(char data, Node* left, Node* right);
		char getData();
		Node* getLeft();
		Node* getRight();
		void setLeft(Node* left);
		void setRight(Node* right);
		void setData(char data);
};