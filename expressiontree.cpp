#include "expressiontree.h"
#include <cmath>

int calculate(int A, int B, std::string Op){
    if(Op == "+") return A+B;
    else if(Op == "-") return A-B;
    else if(Op == "*") return A*B;
    else if(Op == "/") return A/B;
    else if(Op == "^") return int(pow(A,B));
    else return 0;
}
int evauluate(Node* expressionTree){
    if(expressionTree == nullptr) return 0;
    else return calculate(evauluate(expressionTree->left), evauluate(expressionTree->right), expressionTree->datum);
}