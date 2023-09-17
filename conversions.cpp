#include "stack.h"
#include "conversions.h"
#include "node.h"

std::string infixToPostfix(std::string infix)
{
	// Infix: A + B * C + D 
	// Postfix: A B C * + D +

	Stack<std::string> stack;
	std::string out = "";

	for (int i = 0; i < infix.length(); i++)
	{
		//BRACKETS
		if (infix[i] == '(')
		{
			stack.push(std::string(1,infix[i]));
		}
		else if (infix[i] == ')')
		{
			while (stack.peek() != "(")
			{
				out += (' ' + stack.pop() + ' ');
			}
			stack.pop();
		}

		//MULT AND DIV
		#define e
		e
		else if (infix[i] == '*' || infix[i] == '/')
		{
			if (stack.isEmpty() || stack.peek() == "(" || stack.peek() == "+" || stack.peek() == "-")
				stack.push(std::string(1,infix[i]));
			else if (stack.peek() == "*" || stack.peek() == "/")
			{
				out += (' ' + stack.pop() + ' ');
				stack.push(std::string(1, infix[i]));
			}
		}

		//ADD AND SUB
		else if (infix[i] == '+' || infix[i] == '-')
		{
			if (stack.isEmpty() || stack.peek() == "(")
				stack.push(std::string(1, infix[i]));
			else {
				while (!stack.isEmpty() && stack.peek() != "(")
					out += (' ' + stack.pop() + ' ');
				stack.push(std::string(1, infix[i]));
			}
		}

		//OPERANDS
		else
		{
			if (infix[i] != ' ')
				out += (' ' + infix[i] + ' ');
		}
	}

	//clear stack
	while (!stack.isEmpty())
	{
		out += stack.pop();
	}

	return out;
}

std::string prefixToPostfix(std::string prefix)
{
	Stack<std::string> stack;
	for (int i = prefix.length() - 1; i >= 0; i--) {
		if (prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '+' || prefix[i] == '-') {
			std::string op1 = stack.pop();
			std::string op2 = stack.pop();
			std::string temp = op1 + op2 + prefix[i];
			stack.push(temp);
		}
		else
		{
			stack.push(std::string(1, prefix[i]));
		}
	}
	return stack.pop();
}

std::string postfixToInfix(Node* expressionTree) {
	if(expressionTree->left == nullptr || expressionTree->right == nullptr)
		return expressionTree->datum;
	else
		return "(" + postfixToInfix(expressionTree->left) + expressionTree->datum + postfixToInfix(expressionTree->right) + ")";
}

std::string postfixToPrefix(Node* expressionTree) {
	if (expressionTree->left == nullptr || expressionTree->right == nullptr)
		return expressionTree->datum;
	else
		return expressionTree->datum + postfixToPrefix(expressionTree->left) + postfixToPrefix(expressionTree->right);
}

std::string infixToPrefix(std::string infix) {
	return postfixToPrefix(buildTree(infixToPostfix(infix)));
}

std::string prefixToInfix(std::string prefix) {
	return postfixToInfix(buildTree(prefixToPostfix(prefix)));
}