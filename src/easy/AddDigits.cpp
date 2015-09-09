//============================================================================
// Name        : AddDigits.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
// LeetCode No : 258
//============================================================================

#include <iostream>
using namespace std;


int addDigits(int num)
{
	return num>0&&num%9==0 ? 9 : num - 9 * (num / 9);

	//more simple. from https://en.wikipedia.org/wiki/Digital_root
	//return num - 9 * ((num-1) / 9);
}

int main()
{
	int num = 11411;
	printf("addDigits(%d)=%d\n", num, addDigits(num));

	num = 8;
	printf("addDigits(%d)=%d\n", num, addDigits(num));

	num = 14566;
	printf("addDigits(%d)=%d\n", num, addDigits(num));

	num = 39;
	printf("addDigits(%d)=%d\n", num, addDigits(num));

	for(int i=0; i <100; i++)
	{
		printf("addDigits(%d)=%d\n", i, addDigits(i));
	}
}
