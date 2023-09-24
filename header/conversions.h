#pragma once
#include <string>
#include "node.h"

std::string infixToPostfix(std::string infix);
std::string prefixToPostfix(std::string prefix);
std::string postfixToInfix(Node* expressionTree);
std::string postfixToPrefix(Node* expressionTree);
std::string prefixToInfix(std::string prefix);
std::string infixToPrefix(std::string infix);