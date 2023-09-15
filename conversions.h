#pragma once
#include <string>
// Input will be either infix or prefix , output will be postfix.
// This function will convert infix to postfix.
std::string infixToPostfix(std::string infix);
std::string postfixToInfix(std::string postfix);
std::string postfixToPrefix(std::string postfix);
std::string prefixToPostfix(std::string prefix);

std::string infixToPrefix(std::string infix);
std::string prefixToInfix(std::string prefix);