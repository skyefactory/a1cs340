#pragma once
#include <string>
class Node {
public:
	Node();
	Node(char data);
	Node(char data, Node* left, Node* right);
	char datum;
	Node* left;
	Node* right;
};

Node* buildTree(std::string exp);
void printBT(const std::string& prefix, const Node* node, bool isLeft);