#include "stack.h"
#include "conversions.h"
#include "node.h"
#include <string>

std::string infixToPostfix(std::string infix)
{
	// Infix: A + B * C + D 
	// Postfix: A B C * + D +

	Stack stack;
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
				out += stack.pop();
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
				out += stack.pop();
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
					out += stack.pop();
				stack.push(std::string(1, infix[i]));
			}
		}

		//OPERANDS
		else
		{
			out += infix[i];
		}
	}

	//clear stack
	while (!stack.isEmpty())
	{
		out += stack.pop();
	}

	return out;
}

std::string postfixToInfix(std::string postfix)
{
	Stack stack;
	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-')
		{
			std::string op1 =  stack.pop();
			std::string op2 =  stack.pop();
			std::string temp = "(" + op2 + postfix[i] + op1 + ")";
			 stack.push(temp);
		}
		else
		{
			 stack.push(std::string(1,postfix[i]));
		}	
	}
	return  stack.pop();
}

std::string postfixToPrefix(std::string postfix)
{
	Stack stack;
	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
		{
			std::string op1 = stack.pop();
			std::string op2 = stack.pop();
			std::string temp = postfix[i] + op2 + op1;
			stack.push(temp);
		}
		else
		{
			stack.push(std::string(1, postfix[i]));
		}
	}
	return stack.pop();
}

std::string prefixToPostfix(std::string prefix)
{
	Stack stack;
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

std::string infixToPrefix(std::string infix)
{
	return postfixToPrefix(infixToPostfix(infix));
}

std::string prefixToInfix(std::string prefix)
{
	return postfixToInfix(prefixToPostfix(prefix));
}
