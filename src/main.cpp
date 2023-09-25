#include "../header/expressiontree.h"
#include "../header/conversions.h"
#include "../header/node.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	string exp, input;
	greeting:
		cout<<"Welcome! Press any key to start\n";
		cin.get();
		goto input;
	input:
		system("clear");
		exp = "", input="";
		cout<<"Please select your input\n <1> Infix \n <2> Postfix \n <3> Prefix \n <4> Quit\n Enter Numbered Selection: ";
		getline(cin, input);
		if (input == "1") goto infix;
		if (input == "2") goto postfix;
		if (input == "3") goto prefix;
		if (input == "4") goto quit;
		else goto error;

	infix:
		input = "";
		if(exp == "")
		{
			cout<<"Please enter your infix expression. Input would be in the form ( A + B ) / C\n All Operators and operands to be seperated by space\n Expression: ";
			getline(cin,exp);
			system("clear"); 
			if(exp == ""){
				cout<<"No input detected, try again\n";
				system("clear"); 
				goto infix;
			}
		} else system("clear");
		cout<<"Your expression is: "<<exp<<endl<<"What do you want to do? \n <1> Convert to Postfix \n <2> Convert to Prefix \n <3> Visual Expression Tree \n <4> Evauluate Expression w/ Expression Tree \n <5> Enter a new Expression \n <6> Quit \n Selection: ";
		getline(cin, input);
		if (input == "1") { exp = infixToPostfix(exp); goto postfix;}
		if (input == "2") { exp = infixToPrefix(exp); goto prefix;}
		if (input == "3") {printBT("",buildTree(infixToPostfix(exp)),false, true); cin.get(); goto infix;}
		if (input == "4") { cout<<"Result: "<< evauluateTree(buildTree(infixToPostfix(exp)))<<endl; cin.get();goto infix;}
		if (input == "5") goto input;
		if (input == "6") goto quit;
		else goto error;

	postfix:
		input = "";
		if(exp == "")
		{
			cout<<"Please enter your postfix expression. Input would be in the form A B + C / \n All Operators and operands to be seperated by space\n Expression: ";
			getline(cin,exp);
			system("clear"); 
			if(exp == ""){
				cout<<"No input detected, try again\n";
				system("clear"); 			
				goto postfix;
			}
		}else system("clear"); 
		cout<<"Your expression is: "<<exp<<endl<<"What do you want to do? \n <1> Convert to Infix \n <2> Convert to Prefix \n <3> Visual Expression Tree \n <4> Evauluate Expression w/ Expression Tree \n <5> Enter a new Expression \n <6> Quit \n Selection: ";
		getline(cin, input);
		if (input == "1") { exp = postfixToInfix(buildTree(exp)); goto infix;}
		if (input == "2") { exp = postfixToPrefix(buildTree(exp)); goto prefix;}
		if (input == "3") { printBT("",buildTree(exp), false, true); cin.get(); goto postfix;}
		if (input == "4") { cout<<"Result: "<< evauluateTree(buildTree(exp))<<endl; cin.get(); goto postfix;}
		if (input == "5") goto input;
		if (input == "6") goto quit;
		else goto error;

	prefix:
		input = "";
		if(exp == "")
		{
			cout<<"Please enter your prefix expression. Input would be in the form / + A B C \n All Operators and operands to be seperated by space\n Expression: ";
			getline(cin,exp);
			if(exp == ""){
				cout<<"No input detected, try again\n";
				system("clear"); 
				goto prefix;
			}
		}else system("clear"); 
		cout<<"Your expression is: "<<exp<<endl<<"What do you want to do? \n <1> Convert to Postfix \n <2> Convert to Infix \n <3> Visual Expression Tree \n <4> Evauluate Expression w/ Expression Tree \n <5> Enter a new Expression \n <6> Quit \n Selection: ";
		getline(cin, input);
		if (input == "1") { exp = prefixToPostfix(exp); goto postfix;}
		if (input == "2") { exp = prefixToInfix(exp); goto infix;}
		if (input == "3") { printBT("",buildTree(prefixToPostfix(exp)),false,true); cin.get(); goto prefix;}
		if (input == "4") { cout<<"Result: "<< evauluateTree(buildTree(prefixToPostfix(exp)))<<endl; cin.get(); goto prefix;}
		if (input == "5") goto input;
		if (input == "6") goto quit;
		else goto error;
	quit:
		cout<<"Goodbye!\n";
		return 0;
	error:
		system("clear");
		cerr<<"INVALID INPUT - PLEASE TRY AGAIN\n Press any key to try again...";
		cin.get();
		goto input;

}