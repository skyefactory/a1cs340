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

Node::Node(std::string data)
{
    datum = data;
    left = nullptr;
    right = nullptr;
}

Node::Node(std::string data, Node* lft, Node* rght)
{
    datum = data;
    left = lft;
    right = rght;
}

Node* buildTree(std::string exp)
{
    Stack<Node*> stack;
    Node* node = nullptr;
    for (int i = 0; i < exp.length(); i++)
    {
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			Node* right = stack.pop();
			Node* left = stack.pop();
			node = new Node(std::string(1,exp[i]), left, right);
			stack.push(node);
		}
		else
		{
            std::string operand = "";
            while(i < exp.length() && !(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'))
			{
				operand += exp[i];
				i++;
			}
			node = new Node(operand);
			stack.push(node);
		}
    }
    delete node;
    return stack.pop();
}

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|---" : "L___");

        // print the value of the node
        std::cout << node->datum << std::endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

