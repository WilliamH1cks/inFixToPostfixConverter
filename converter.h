#pragma once

#include <stack>
#include <iostream>
using namespace std;

class converter
{
	private:
		string postfix;
		stack<char> symbols;
	public:
		//Precond: A well-formatted infix expression is entered
		//Postcond: The expression is converted to postfix format
		string convert(string);

		//Precond: The current character in the infix operation is an operator
		//Postcond: Returns true if the current infix character's precedence <= the stack's top operator precedence
		bool orderPrecedence(char, char);
		
};

