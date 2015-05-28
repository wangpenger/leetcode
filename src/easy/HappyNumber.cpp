//============================================================================
// Name        : HappyNumber.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Write an algorithm to determine if a number is "happy".
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

//n=15;
//sumInt = 1*1 + 5*5 = 26
int sumInt(int n)
{
	int iSum = 0;
	do
	{
		iSum += pow(n % 10, 2);
		n /= 10;
	} while(n);
	return iSum;
}

bool isHappy(int n)
{
	unordered_map<int, int> intMap;

	if(n <= 0)
	{
		return false;
	}
	while(n)
	{
		int iRet = sumInt(n);
		if(n == 1)
		{
			return true;
		}
		else if(intMap.end() != intMap.find(iRet))
		{
			return false;
		}
		else
		{
			intMap[iRet] = n;
			n = iRet;
			continue;
		}
	}
	return false;
}

int main()
{
	printf("isHappy(%d)=%d\n", -2, isHappy(-2));
	printf("isHappy(%d)=%d\n", 0, isHappy(0));
	printf("isHappy(%d)=%d\n", 1, isHappy(1));
	printf("isHappy(%d)=%d\n", 15, isHappy(15));
	printf("isHappy(%d)=%d\n", 19, isHappy(19));
}
