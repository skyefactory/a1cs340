#include "../header/node.h"
#include "../header/stack.h"
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

Node::Node(std::string data, Node* rght, Node* lft)
{
    datum = data;
    left = lft;
    right = rght;
}

Node* buildTree(std::string exp)
{
    std::string a = "";
    Stack<Node*> stack;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ')
        {
            if(a == "" || a==" "){
                a="";
                continue;
            }
            else 
            {
                stack.push(new Node(a));
                a = "";
                continue;
            }
        }
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            if(a != ""){
                stack.push(new Node(a));
                a = "";
            }
            stack.push(new Node(std::string(1,exp[i]), stack.pop(), stack.pop()));
            continue;
        }
        if(int(exp[i]) <=60 && 71 >= int(exp[i]))
        {  
            a+=exp[i];
            continue;
        }
    }
    return stack.pop();
}


void printBT(const std::string& prefix, const Node* node, bool isLeft, bool isRoot)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "R---" : "L---");

        // print the value of the node
        std::cout << "[ " << node->datum <<" ]" << std::endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true ,false);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false ,false);
    }
}

