/*
* University of Regina - CS340 Fall 2023
* Dylan Ostapa - #200463707
* Assigment 1 Due Sept 25, 2023
*/

#include "conversions.h"
#include "node.h"
#include <iostream>
#include <string>
using namespace std;


// Interface
int main() {
/*
* Features:
* INFIX -> POSTFIX
* INFIX -> PREFIX
* POSTFIX -> INFIX
* POSTFIX -> PREFIX
* PREFIX -> INFIX
* PREFIX -> POSTFIX
* VISUAL TREE
* EVALUATE TREE
*/
	string i1, i2;
	string exp ="";

// Silly control flow management to allow for easy navigation and smoothness

begin:
	cout << "Welcome \n";
	goto input;

exit:
	cout << "Goodbye, Exiting Program \n";
	return 0;

prefix:
	if (exp == "") {
		cout << "Please enter a prefix expression: \n";
		getline(cin, exp);
		if (exp == "" || exp == " "){
			cout<<"No input detected, try again\n";
			exp = ""; goto prefix;
		}
	} 
	
	cout << "Your expression is: " + exp + " \n What would you like to do ? \n(1) Prefix to Infix \n(2) Prefix to Postfix \n(3) Prefix to Visual Tree \n(4) Evauluate Prefix \n(5) Back \n(6) Exit Program \n";
	getline(cin, i2);
	if(i2 == "1"){
		i1 = "", i2="";
		exp = prefixToInfix(exp);
		goto infix;
	}
	if (i2 == "2") {
		i1 = "", i2 = "";
		exp = prefixToPostfix(exp);
		goto postfix;
	}
	if (i2 == "3")
	{
		printBT("", buildTree(prefixToPostfix(exp)), false);
		goto prefix;
	}
		
	if (i2 == "4")
		exp = "Not Implemented";
	if (i2 == "5") {
		i1 = "", i2 = "", exp = "";
		goto input;
	}
	if (i2 == "6")
		goto exit;

postfix:
	if (exp == "") {
		cout << "Please enter a postfix expression: \n";
		getline(cin, exp);
		if (exp == "" || exp == " "){
			cout<<"No input detected, try again\n";
			exp = ""; 
			goto postfix;
		}
	}
	cout << "Your expression is: " + exp + " \n What would you like to do ? \n(1) Postfix to Infix \n(2) Postfix to Prefix \n(3) Postfix to Visual Tree \n(4) Evauluate Postfix \n(5) Back \n(6) Exit Program \n";
	getline(cin, i2);
	if (i2 == "1") {
		exp = postfixToInfix(buildTree(exp));
		goto infix;
	}
	if (i2 == "2") {
		i1 = "", i2 = "";
		exp = postfixToPrefix(buildTree(exp));
		goto prefix;
	}
	if (i2 == "3")
	{
		printBT("", buildTree(exp), false);
		goto postfix;
	}
	if (i2 == "4")
		exp = "Not Implemented";
	if (i2 == "5"){
		i1 = "", i2 = "", exp = "";
		goto input;
	}
	if (i2 == "6")
		goto exit;
infix:
	if (exp == "") {
		cout << "Please enter a infix expression: \n";
		getline(cin, exp);
		if (exp == "" || exp == " "){
			cout<<"No input detected, try again\n";
			exp = ""; goto infix;
		}
	}
	cout << "Your expression is: " + exp + " \n What would you like to do ? \n(1) Infix to Postfix \n(2) Infix to Prefix \n(3) Infix to Visual Tree \n(4) Evauluate Infix \n(5) Back \n(6) Exit Program \n";
	getline(cin, i2);
	if (i2 == "1") {
		i1 = "", i2 = "";
		exp = infixToPostfix(exp);
		goto postfix;
	}
	if (i2 == "2") {
		i1 = "", i2 = "";
		exp = infixToPrefix(exp);
		goto prefix;
	}
	if (i2 == "3"){
		printBT("", buildTree(infixToPostfix(exp)), false);
		goto infix;
	}
	if (i2 == "4")
		exp = "Not Implemented";
	if (i2 == "5") {
		goto input;
	}
	if (i2 == "6")
		goto exit;

invalid:
	cout << "Invalid Input, clearing. Please try again. \n";
		exp = "", i1 = "", i2 = "";
		goto input;

input:
	exp = "", i1 = "", i2 = "";
	cout << "What type of input? \n (1) Postfix \n (2) Prefix \n (3) Infix \n (4) Exit Program \n";
	cout << "--->: ";
	getline(cin, i1);
	if (i1 == "1") goto postfix;
	else if (i1 == "2") goto prefix;
	else if (i1 == "3") goto infix;
	else if (i1 == "4") goto exit;
	else goto invalid;



}