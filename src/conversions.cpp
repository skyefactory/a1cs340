#include "../header/stack.h"
#include "../header/conversions.h"
#include <algorithm> 
bool isOperand(char ch){
    return (ch>='a' && ch<='z') || (ch>='A' && ch <='Z') || (ch>='0' && ch<='9');
}
bool isOperator(char ch){
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')');
}
//Use Stack

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
				out += stack.pop();
			}
			stack.pop();
		}

		else if (infix[i] == '*' || infix[i] == '/')
		{
			if (stack.isEmpty() || stack.peek() == "(" || stack.peek() == "+" || stack.peek() == "-")
				stack.push(std::string(1,infix[i]));
			else if (stack.peek() == "*" || stack.peek() == "/")
			{
				out += (stack.pop());
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
			while(i < infix.length() && infix[i] !=' ' && isOperand(infix[i])){
				out+= infix[i];
				i++;
			}
			out +=" ";
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
	std::string buf = "";
	Stack<std::string> stack;
	for (int i = prefix.length() - 1; i >= 0; i--) 
	{
		if(isOperator(prefix[i]))
		{
			std::string a = stack.pop();
			std::string b = stack.pop();
			std::string exp = a + b + std::string(1,prefix[i]) + " ";
			stack.push(exp);
		}
	else if(isOperand(prefix[i])){
		while(i >= 0 && isOperand(prefix[i])){
			buf.append(std::string(1,prefix[i]));
			i--;
		}
		reverse(buf.begin(), buf.end());
		buf.append(" ");
		stack.push(buf);
		buf = "";


	}
}
	return stack.pop();
}
//Use ExpressionTree 

	// In Order traversal
std::string postfixToInfix(Node* expressionTree) {
	if(expressionTree->right == nullptr || expressionTree->left == nullptr) 
		return expressionTree->datum;
	std::string a = postfixToInfix(expressionTree->right);
	std::string b = postfixToInfix(expressionTree->left);
	return (("( "+a + " " + expressionTree->datum + " " + b + " )")); 
}
	// Pre Order traversal
std::string postfixToPrefix(Node* expressionTree) {
	if(expressionTree->right == nullptr || expressionTree->left == nullptr) 
		return expressionTree->datum;
	std::string a = postfixToPrefix(expressionTree->right);
	std::string b = postfixToPrefix(expressionTree->left);
	return (expressionTree->datum + " " + a + " " + b);
}

	// infixToPostfix -> build tree from postfix -> pre order traversal
std::string infixToPrefix(std::string infix) {
	return postfixToPrefix(buildTree(infixToPostfix(infix)));
}
	// prefixToPostfix -> build tree from postfix -> in order traversal.
std::string prefixToInfix(std::string prefix) {
	return postfixToInfix(buildTree(prefixToPostfix(prefix)));
}