//============================================================================
// Name        : ValidParentheses.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//============================================================================

#include <iostream>
#include <map>
using namespace std;
static map<char, int> charHash;

bool isValid(string s)
{
	charHash['('] = 1;
	charHash[')'] = 1;
	charHash['{'] = 2;
	charHash['}'] = 2;
	charHash['['] = 3;
	charHash[']'] = 3;
	if(s.length() == 0 || s.length() % 2 != 0)
	{
		return false;
	}

	string strTmp = "";
	for(int i=0; i<s.length() - 1; i++)
	{
		map<char, int>::iterator it = charHash.find(s[i]);
		map<char, int>::iterator it2 = charHash.find(s[i + 1]);
		if(it->first != it2->first && it->second == it2->second)
		{
			if(s.length() == 2)
			{
				return true;
			}
			strTmp = s.substr(0, i) + s.substr(i+2);
			isValid(strTmp);
		}
	}
	return false;
}

int main()
{
//	printf("isValid(%s)=%d\n", string("()").c_str(), isValid("()"));
	printf("isValid(%s)=%d\n", string("()[]{}").c_str(), isValid("()[]{}"));
//	printf("isValid(%s)=%d\n", string("(]").c_str(), isValid("(]"));
//	printf("isValid(%s)=%d\n", string("([)]").c_str(), isValid("([)]"));
//	printf("isValid(%s)=%d\n", string("((").c_str(), isValid("(("));
//	printf("isValid(%s)=%d\n", string("([])").c_str(), isValid("([])"));
}
