#include "../header/expressiontree.h"
#include <iostream>
#include <cmath>
#define error INT_MAX;


int calculate(int A, int B, char op)
{
    switch(op){
        case('+'):
            return A + B;
        case('-'):
            return A - B;
        case('*'):
            return A * B;
        case('/'):
        //type casting.
            return round(double(A) / double(B));
        default:
            return error; 
    }
    return error;
}

int evauluateTree(Node* tree){
    if(tree != nullptr)
    {
        //Wierd code but it works. If datum is an operand, the stoi should be successful. If it throws an invalid argument, then it must be an operator or invalid char.
        try {
            return stoi(tree->datum);
            } 
            catch (const std::invalid_argument& ia){
                //calculate right->op->left
                return (calculate(evauluateTree(tree->right), evauluateTree(tree->left), tree->datum[0])) ;
            }
        }
            return -1;
}
