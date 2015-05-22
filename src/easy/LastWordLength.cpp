//============================================================================
// Name        : LastWordLength.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Return the length of last word in the string
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int lengthOfLastWord(string s)
{
	if(s.length() == 0)
	{
		return 0;
	}
	string::size_type idx_space = s.rfind(" ");
	if(string::npos == idx_space)
	{
		return s.length();
	}
	else if(s.length() - 1 == idx_space)
	{
		return lengthOfLastWord(s.substr(0, s.length() - 1));
	}
	return s.length() - 1 - idx_space;
}

int main()
{
	printf("lengthOfLastWord(%s)=%d\n", "Hello World", lengthOfLastWord("Hello World"));
	printf("lengthOfLastWord(%s)=%d\n", "Hello World 123", lengthOfLastWord("Hello World 123"));
	printf("lengthOfLastWord(%s)=%d\n", "Hello World 12345", lengthOfLastWord("Hello World 12345"));
	printf("lengthOfLastWord(%s)=%d\n", "", lengthOfLastWord(""));
	printf("lengthOfLastWord(%s)=%d\n", "   ", lengthOfLastWord("   "));
	printf("lengthOfLastWord(%s)=%d\n", "Hello", lengthOfLastWord("Hello"));
	printf("lengthOfLastWord(%s)=%d\n", "a", lengthOfLastWord("a"));
	printf("lengthOfLastWord(%s)=%d\n", "a   ", lengthOfLastWord("a   "));
	printf("lengthOfLastWord(%s)=%d\n", "hello a     ", lengthOfLastWord("hello a     "));
}
