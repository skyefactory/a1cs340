#include "node.h"
#include "stack.h"
#include <string>
#include <iostream>

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

Node::Node(char data, Node* rght, Node* lft)
{
    datum = data;
    left = lft;
    right = rght;
}

Node* buildTree(std::string exp)
{
    Stack<Node*> stack;
    for (int i = 0; i < exp.length(); i++) {
        if ( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            stack.push(new Node(exp[i], stack.pop(), stack.pop()));
        }
        else if (exp[i] != ' '){
            stack.push(new Node(exp[i]));
        }
    }
        return stack.pop();
}

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "R---" : "L---");

        // print the value of the node
        std::cout << "[ " << node->datum <<" ]" << std::endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

