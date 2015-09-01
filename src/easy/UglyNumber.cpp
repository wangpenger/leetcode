//============================================================================
// Name        : UglyNumber.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Write a program to check whether a given number is an ugly number.
// LeetCode No : 263
//============================================================================

#include <iostream>
#include <queue>
using namespace std;


bool isUgly(int num)
{
	if(num == 0)
	{
		return false;
	}
	if(num == 1 || num == 2 || num == 3 || num == 5)
	{
		return true;
	}
	else if(num % 2 == 0)
	{
		return isUgly(num / 2);
	}
	else if (num % 3 == 0)
	{
		return isUgly(num / 3);
	}
	else if (num % 5 == 0)
	{
		return isUgly(num / 5);
	}
	else
	{
		return false;
	}
	return false;
}

int main()
{
	int num = 6;
	printf("isUgly(%d)=%d\n", num, isUgly(num));

	num = 8;
	printf("isUgly(%d)=%d\n", num, isUgly(num));

	num = 14;
	printf("isUgly(%d)=%d\n", num, isUgly(num));

	num = 39;
	printf("isUgly(%d)=%d\n", num, isUgly(num));

	for(int i=1; i <100; i++)
	{
		printf("isUgly(%d)=%d\n", i, isUgly(i));
	}
}
