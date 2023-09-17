#pragma once
#include <string>
class Node {
public:
	Node();
	Node(std::string data);
	Node(std::string data, Node* left, Node* right);
	std::string datum;
	Node* left;
	Node* right;
};

Node* buildTree(std::string exp);
void printBT(const std::string& prefix, const Node* node, bool isLeft);