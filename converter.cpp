#pragma once

#include "converter.h"
#include <iostream>
#include <stack>

#include <cctype> //For checking what each character is
using namespace std;

bool converter::orderPrecedence(char pfxChar, char stackChar)
{
	if (stackChar == '(')
		return false;
	else if (pfxChar == '*' || pfxChar == '/')
	{
		if (stackChar == '*' || stackChar == '/')
			return true;
		else if (stackChar == '+' || stackChar == '-')
			return false;
	}
	else if (pfxChar == '+' || pfxChar == '-')
	{
		return true;
	}
}

string converter::convert(string infix)
{
	string postfix = "";
	for (int i = 0; i < infix.length(); i++)
	{
		if (isalpha(infix[i]))
			postfix += infix[i];

		else if (infix[i] == '(')
			symbols.push(infix[i]);

		else if (infix[i] == ')')
		{
			if (!symbols.empty())
			{
				while (symbols.top() != '(')
				{
					postfix += symbols.top();
					symbols.pop();
				}

				symbols.pop();
			}
		}
		else if (infix[i] == ' ');
		else
		{
			while (!symbols.empty() && orderPrecedence(infix[i], symbols.top()))
			{
				postfix += symbols.top();
				symbols.pop();
			}
			symbols.push(infix[i]);
		}
	}

	while (!symbols.empty())
	{
		postfix += symbols.top();
		symbols.pop();
	}

	return postfix;
}