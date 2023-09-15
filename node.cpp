#include "node.h"

Node::Node()
{
    datum = '0';
    left = nullptr;
    right = nullptr;

}

Node::Node(char data)
{
    datum = data;
    left = nullptr;
    right = nullptr;
}

Node::Node(char data, Node* lft, Node* rght)
{
    datum = data;
    left = lft;
    right = rght;
}

char Node::getData()
{
    return datum;
}

Node* Node::getLeft()
{
    return left;
}

Node* Node::getRight()
{
    return right;
}

void Node::setLeft(Node* left)
{
    this->left = left;
}

void Node::setRight(Node* right)
{
    this->right = right;
}

void Node::setData(char data)
{
    datum = data;
}
                